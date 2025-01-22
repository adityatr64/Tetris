#include "grid.h"
#include "colors.h"
#include <iostream>
#include <vector>

Grid::Grid() // constructor
{
  rowSize = 17;
  columnSize = 10;
  cellSize = 30; // pixels
  init();
  colors = GetColors();
}

void Grid::init()
{
  for (int row = 0; row < rowSize; row++)
  {
    for (int column = 0; column < columnSize; column++)
    {
      grid[row][column] = 0;
    }
  }
}

void Grid::printGrid()
{
  for (int row = 0; row < rowSize; row++)
  {
    for (int column = 0; column < columnSize; column++)
    {
      std::cout << grid[row][column] << " ";
    }
    std::cout << std::endl;
  }
}

void Grid::DrawGrid()
{
  for (int row = 0; row < rowSize; row++)
  {
    for (int column = 0; column < columnSize; column++)
    {
      int colorVal = grid[row][column];                                                                       // 30x30 pixels
      DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[colorVal]); //  -/+ is for offset
    }
  }
}

int Grid::WindowCheck(int x, int y)
{
  if (x < 0)
  {
    return 4;
  }
  else if (y < 0)
  {
    return 1; // left overflow
  }
  else if (x >= rowSize)
  {
    return 3; // bottom overflow
  }
  else if (y >= columnSize)
  {
    return 2; // right overflow
  }
  // try to write a switch if possible not needed tbh cos compiler optimizations
  return 0;
}

bool Grid::BlockCheck(int x, int y)
{
  if (grid[x][y] != 0)
  {
    return true;
  }
  return false;
}

int Grid::UpdateGrid()
{
  int rowsCleared = 0;
  for (int row = rowSize; row >= 0; row--)
  {
    if (RowComplete(row))
    {
      ClearRow(row);
      rowsCleared++;
    }
    else if (rowsCleared > 0)
    {
      ShiftRow(row, rowsCleared);
    }
  }
  return 0;
}

void Grid::ShiftRow(int row, int n)
{
  for (int column = 0; column < columnSize; column++)
  {
    std::cout << "Shifting row " << row << " by " << n << std::endl;
    grid[row + n][column] = grid[row][column]; // shift
    grid[row][column] = 0;                     // clear
  }
}

bool Grid::RowComplete(int row)
{
  for (int column = 0; column < columnSize; column++)
  {
    if (grid[row][column] == 0)
    {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row)
{ // add animations and score
  for (int column = 0; column < columnSize; column++)
  {
    grid[row][column] = 0;
  }
}