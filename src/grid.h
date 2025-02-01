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
  int WindowCheck(int, int);
  bool BlockCheck(int, int);
  int grid[20][10];
  int UpdateGrid();

private:
  bool RowComplete(int);
  void ClearRow(int);
  void ShiftRow(int, int);
  int rowSize;
  int columnSize;
  int cellSize;
  std::vector<Color> colors;
};
