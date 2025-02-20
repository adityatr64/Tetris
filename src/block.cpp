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
    // DrawRectangle(450 - 90 + item.y * cellSize, item.x * cellSize, cellSize - 1, cellSize - 1, colors[id]);
    Rectangle rec = {(float)(item.y * cellSize + 390 - 90), (float)(15 + item.x * cellSize), (float)(cellSize - 1), (float)(cellSize - 1)}; // x,y,w,h
    DrawRectangleRounded(rec, 0.24, 1, colors[id]);
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

void Block::RotateBlock()
{
  ++rotation;
  if (rotation > 3)
  {
    rotation = 0;
  }
}

void Block::UnRotateBlock()
{
  --rotation;
  if (rotation < 0)
  {
    rotation = 3;
  }
}

void Block::KickBack(int from)
{
  switch (from)
  {
  case 1:
    MoveBlock(0, 1);
    break;
  case 2:
    MoveBlock(0, -1);
    break;
  case 3:
    MoveBlock(-1, 0);
    break;
  case 4:
    MoveBlock(1, 0);
    break;
  default:
    break;
  }
}
