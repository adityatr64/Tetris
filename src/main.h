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

  void ControlBlock(char);

private:
  bool _windowCheck();
  void _RotateBlock();
  std::vector<Block> blocks;
  Block cur;
  Block next;
};