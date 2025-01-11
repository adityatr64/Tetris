#include "block.h"

position::position(int x, int y)
{
  this->x = x; // self from python basically
  this->y = y;
}

Block::Block()
{
  rowOff = 0;
  colOff = 0;
  cellSize = 30;
  rotation = 0;
  colors = GetColors();
}

void Block::DrawBlock()
{
  std::vector<position> tiles = GetBlockPos(); // makes a tile and sets the rotation
  for (position item : tiles)
  {
    DrawRectangle(item.y * cellSize, item.x * cellSize, cellSize - 1, cellSize - 1, colors[id]);
  }
}

void Block::MoveBlock(int x, int y)
{
  rowOff += x;
  colOff += y;
}

std::vector<position> Block::GetBlockPos()
{
  std::vector<position> tiles = cells[rotation];
  std::vector<position> moved;
  for (position item : tiles)
  {
    position newPos = position(item.x + rowOff, item.y + colOff);
    moved.push_back(newPos);
  }
  return moved;
}
