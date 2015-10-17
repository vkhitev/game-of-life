#include "Cell.h"

#include <cassert>

Cell::Cell(char condition)
	: mCellRepresentation()
	, nNeighbours(0)
{
	assert(((condition == kDeadCell) || (condition == kAliveCell)) && "Cell::Cell - wrong agrument (condition)");
	mCellRepresentation = condition;
}

void Cell::revive()
{
	mCellRepresentation = kAliveCell;
}

void Cell::kill()
{
	mCellRepresentation = kDeadCell;
}

bool Cell::isAlive() const
{
	return (mCellRepresentation == kAliveCell);
}

bool Cell::mustRevive() const
{
	return (!isAlive() && (nNeighbours == 3));
}

bool Cell::mustDie() const
{
	return (isAlive() && (nNeighbours < 2 || nNeighbours > 3));
}

void Cell::draw() const
{
	std::cout << mCellRepresentation;
}

void Cell::addNeighbour()
{
	nNeighbours++;
}

void Cell::resetNeighbours()
{
	nNeighbours = 0;
}