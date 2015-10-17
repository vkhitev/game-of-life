#include "World.h"
#include <string>
#include <cassert>
#include <algorithm>
#include <thread>
#include <chrono>

World::World()
	: mGrid(kDefaultRows, kDefaultCols)
	, mActiveCells()
{

}

World::World(const Grid<Cell>& grid)
	: mGrid(grid)
	, mActiveCells()
{
	addAllActiveNeighbours();
}

World::World(const std::vector<std::string>& grid)
	: mGrid(grid.size(), grid[0].size())
	, mActiveCells()
{
	bool rowsLengthsAreEqual = std::all_of(std::cbegin(grid) + 1, std::cend(grid),
		[&grid](const std::string& row) { return row.size() == grid.front().size(); });

	assert(rowsLengthsAreEqual && "World::World - rows have different length");

	for (int i = 0; i < mGrid.getNumRows(); i++)
	{
		for (int j = 0; j < mGrid.getNumCols(); j++)
		{
			mGrid(i, j) = grid[i][j];
		}
	}

	addAllActiveNeighbours();
}

void World::run()
{
	while (!mActiveCells.empty())
	{
		draw();
		update();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		reset();
		addAllActiveNeighbours();
	}
}

void World::update()
{
	std::vector<Vector2i> toDelete;
	for (auto& pair : mActiveCells)
	{
		Cell* cell = pair.second;
		if (cell->mustDie())
		{
			cell->kill();
		}
		if (cell->mustRevive())
		{
			cell->revive();
		}
	}
}

void World::draw() const
{
	mGrid.draw();
}

void World::reset()
{
	for (int i = 0; i < mGrid.getNumRows(); i++)
	{
		for (int j = 0; j < mGrid.getNumCols(); j++)
		{
			mGrid(i, j).resetNeighbours();
		}
	}
	mActiveCells.clear();
}

void World::addActiveNeighboursAt(int i, int j)
{
	Vector2i position(i, j);
	
	int rows = mGrid.getNumRows();
	int cols = mGrid.getNumCols();

	Neighbours neighbours(position);
	for (int iter = 0; iter < 8; iter++)
	{
		int& x = neighbours.directions[iter].x;
		int& y = neighbours.directions[iter].y;
		if (mGrid.isOutOfBounds(x, y))
		{
			neighbours.reverse(iter, rows, cols);
		}
		if (mGrid(y, x).isAlive())
		{
			mGrid(j, i).addNeighbour();
		}
		else
		{
			mGrid(y, x).addNeighbour();
			// +9000 to effectiveness
			if (std::count_if(std::cbegin(mActiveCells), std::cend(mActiveCells),
				[&x, &y](const auto& pair) { return pair.first == Vector2i(x, y); }) == 0)
			{
				mActiveCells.insert(std::make_pair(Vector2i(x, y), &mGrid(y, x)));
			}
		}
	}
}

void World::addAllActiveNeighbours()
{
	for (int i = 0; i < mGrid.getNumRows(); i++)
	{
		for (int j = 0; j < mGrid.getNumCols(); j++)
		{
			if (mGrid(i, j).isAlive())
			{
				//                that is ok :)             j, i          i, j
				mActiveCells.insert(std::make_pair(Vector2i(j, i), &mGrid(i, j)));
				addActiveNeighboursAt(j, i);
			}
		}
	}
}