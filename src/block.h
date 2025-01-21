#pragma once
#include <vector>
#include <map>
#include "colors.h"
class position
{
public:
  position(int x, int y);
  int x;
  int y;
};

class Block
{
private:
  int cellSize;
  int rotation;
  std::vector<Color> colors;
  int rowOff;
  int colOff;

public:
  Block();
  void DrawBlock();
  void MoveBlock(int x, int y);
  std::vector<position> GetBlockPos();
  int id;
  std::map<int, std::vector<position>> cells;
  void RotateBlock();
  void UnRotateBlock();
  void KickBack(int);
};
