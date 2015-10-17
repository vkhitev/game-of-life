#include <iostream>
#include <cassert>
#include "Cell.h"
#include "Grid.h"

template <typename T>
inline Grid<T>::Grid(int rows, int cols)
	: mGrid()
{
	assert(rows > 0 && "Grid::Grid - wrong parameter (rows > 0)");
	assert(cols > 0 && "Grid::Grid - wrong parameter (cols > 0)");

	mGrid.resize(rows);
	for (auto& column : mGrid)
	{
		column.resize(cols);
	}
}

template <typename T>
inline int Grid<T>::getNumCols() const
{
	return mGrid[0].size();
}

template <typename T>
inline int Grid<T>::getNumRows() const
{
	return mGrid.size();
}

template <typename T>
inline void Grid<T>::draw() const
{
	system("cls");
	for (const auto& row : mGrid)
	{
		for (const auto& element : row)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}

template <>
inline void Grid<Cell>::draw() const
{
	system("cls");
	for (const auto& row : mGrid)
	{
		for (const auto& element : row)
		{
			element.draw();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
inline void Grid<T>::setElementAt(int x, int y, const T& element)
{
	mGrid[x][y] = element;
}

template<typename T>
inline T& Grid<T>::getElementAt(int x, int y)
{
	return mGrid[x][y];
}

template<typename T>
inline const T& Grid<T>::getElementAt(int x, int y) const
{
	return mGrid[x][y];
}

template<typename T>
inline T& Grid<T>::operator()(int i, int j)
{
	return mGrid[i][j];
}

template<typename T>
inline const T & Grid<T>::operator()(int i, int j) const
{
	return mGrid[i][j];
}

template<typename T>
inline bool Grid<T>::isOutOfBounds(int i, int j) const
{
	return (i < 0 || i >= getNumCols() || j < 0 || j >= getNumRows());
}