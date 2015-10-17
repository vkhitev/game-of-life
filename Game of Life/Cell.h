#pragma once
#include <iostream>

class Cell
{
public:
	Cell(char condition = kDeadCell);

	void revive();
	void kill();

	bool isAlive() const;
	bool mustRevive() const;
	bool mustDie() const;

	void draw() const;

	void addNeighbour();
	void resetNeighbours();

private:
	const static char kAliveCell = '+';
	const static char kDeadCell = 'o';

	char mCellRepresentation;
	int nNeighbours;
};