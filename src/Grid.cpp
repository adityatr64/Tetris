#include "grid.h"
#include "colors.h"
#include <iostream>
#include <vector>
Grid::Grid() // constructor
{
  rowSize = 24;
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