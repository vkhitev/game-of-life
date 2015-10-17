#pragma once

#include <vector>

template <typename T>
class Grid
{
public:
	explicit Grid(int rows = kDefaultRows, int cols = kDefaultCols);

	int getNumCols() const;
	int getNumRows() const;

	void draw() const;

	void setElementAt(int x, int y, const T& element);

	T& getElementAt(int x, int y);
	const T& getElementAt(int x, int y) const;

	T& operator()(int i, int j);
	const T& operator()(int i, int j) const;

	bool isOutOfBounds(int i, int j) const;

private:
	std::vector<std::vector<T>> mGrid;

	const static int kDefaultRows = 15;
	const static int kDefaultCols = 15;
};

#include "Grid.inl"