#pragma once
#include "grid.h"
#include "block.h"
class Game
{
public:
  Game();
  Block GetRandomBlock();
  void Draw();
  Grid grid;
  void HandleInput();

private:
  std::vector<Block> blocks;
  Block cur;
  Block next;
};