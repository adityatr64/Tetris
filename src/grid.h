#pragma once // Basically includes the file only once
#include <vector>
#include <raylib.h>
class Grid
{
public:
  Grid();
  void init();
  void printGrid();
  void DrawGrid();
  int grid[24][10];

private:
  int rowSize;
  int columnSize;
  int cellSize;
  std::vector<Color> colors;
};
