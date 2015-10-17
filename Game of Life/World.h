#pragma once

#include "Cell.h"
#include "Grid.h"
#include <map>
#include <initializer_list>

struct Vector2i
{
	Vector2i(int x, int y) : x(x), y(y) { };
	friend bool operator<(const Vector2i& a, const Vector2i& b) { return (a.x < b.x && a.y < b.y); };
	friend bool operator==(const Vector2i& a, const Vector2i& b) { return (a.x == b.x && a.y == b.y); };
	friend Vector2i& operator+(const Vector2i& a, const Vector2i& b) { return Vector2i { a.x + b.x, a.y + b.y }; };
	friend Vector2i& operator-(const Vector2i& a, const Vector2i& b) { return Vector2i { a.x - b.x, a.y - b.y }; };
	void operator+=(const Vector2i& a) { x += a.x; y += a.y; };
	int x;
	int y;
};

struct Neighbours
{
	enum Directions
	{
		top_left = 0,
		top,
		top_right,
		right,
		bottom_right,
		bottom,
		bottom_left,
		left,
	};

	Neighbours(const Vector2i& position)
		: directions(8, position)
	{
		directions[top_left] += Vector2i(-1, -1);
		directions[top] += Vector2i(0, -1);
		directions[top_right] += Vector2i(1, -1);
		directions[right] += Vector2i(1, 0);
		directions[bottom_right] += Vector2i(1, 1);
		directions[bottom] += Vector2i(0, 1);
		directions[bottom_left] += Vector2i(-1, 1);
		directions[left] += Vector2i(-1, 0);
	}

	void reverse(int i, int rows, int cols)
	{
		assert(i >= 0 && i <= 8 && "Neighbour::reverse - i >= 0 && i <= 8");
		int& x = directions[i].x;
		int& y = directions[i].y;

		switch (i)
		{	
			case top_left:
				if (x < 0) x = cols - 1;
				if (y < 0) y = rows - 1;
				break;
			case top:
				y = rows - 1;
				break;
			case top_right:
				if (x >= cols) x = 0;
				if (y < 0) y = rows - 1;
				break;
			case right:
				x = 0;
				break;
			case bottom_right:
				if (x >= cols) x = 0;
				if (y >= rows) y = 0;
				break;
			case bottom:
				y = 0;
				break;
			case bottom_left:
				if (x < 0) x = cols - 1;
				if (y >= rows) y = 0;
				break;
			case left:
				x = cols - 1;
				break;
			default:
				break;
		}
	}

	std::vector<Vector2i> directions;
};

class World
{
public:
	World();
	World(const Grid<Cell>& grid);
	World(const std::vector<std::string>& grid);

	void run();

private:
	void update();
	void draw() const;
	void reset();

	void addActiveNeighboursAt(int i, int j);
	void addAllActiveNeighbours();

	/* Just for drawing */
	Grid<Cell> mGrid;

	/* All calculations will be here */
	std::multimap<Vector2i, Cell*> mActiveCells;

	const static int kDefaultRows = 15;
	const static int kDefaultCols = 15;
};