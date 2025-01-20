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
    return 1;
  }
  else if (y < 0)
  {
    return 1; // left overflow
  }
  else if (x >= rowSize)
  {
    return 2; // right overflow
  }
  else if (y >= columnSize)
  {
    return 3; // bottom overflow
  }
  else if (y < 0)
  {
    return 4; // top overflow
  }
  return 0;
}