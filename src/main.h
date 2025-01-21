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
  void LockBlock();
  bool _blockCheck();
  void _kickBack(int);
  int _windowCheck();
  void _RotateBlock();
  void _unRotateBlock();
  std::vector<Block> blocks;
  Block cur;
  Block next;
};