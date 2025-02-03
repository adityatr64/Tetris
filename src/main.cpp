#include <raylib.h>
#include "grid.h"
#include "ChildBlocks.cpp"
#include "main.h"
#include <random>
#include <iostream>

double lastUpdateTick = 0;
int invincibilityFrames = 0; // change this
double tickRate = 0.4;

bool UpdateTick(double tickRate)
{
  if (GetTime() - lastUpdateTick >= tickRate)
  {
    lastUpdateTick = GetTime();
    return true;
  }
  return false;
}

Game::Game()
{
  grid = Grid();
  blocks = {T_BLOCK(), L_BLOCK(), J_BLOCK(), S_BLOCK(), Z_BLOCK(), O_BLOCK(), I_BLOCK()};
  cur = GetRandomBlock();
  next = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
  // this looks like a hardware random number generator
  // idk i yoiked it from stackoverflow
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, blocks.size() - 1);
  return blocks[dis(gen)];
}

void Game::Draw()
{
  grid.DrawGrid();
  cur.DrawBlock();
  if (_blockCheck())
  {
    cur.MoveBlock(-1, 0);
    if (_windowCheck() == 4)
    {
      cur.MoveBlock(1, 0);
      std::cout << "Game Over" << std::endl;
      exit(0); // game over
    }
  }
}

void Game::HandleInput()
{
  // takes input
  int key = GetKeyPressed();
  switch (key)
  {
  case KEY_LEFT:
    ControlBlock('l'); // move left
    break;
  case KEY_RIGHT:
    ControlBlock('r'); // move right
    break;
  case KEY_DOWN:
    ControlBlock('d'); // move down
    break;
  case KEY_UP:
    ControlBlock('u'); // rotate
    break;
  default:
    break;
  }
}

void Game::ControlBlock(char dir)
{
  switch (dir)
  {
  case 'l':
    cur.MoveBlock(0, -1);
    if (_windowCheck() || _blockCheck())
    {
      cur.MoveBlock(0, 1);
    }
    break;
  case 'r':
    cur.MoveBlock(0, 1);
    if (_windowCheck() || _blockCheck())
    {
      cur.MoveBlock(0, -1);
    }
    break;
  case 'd':
    cur.MoveBlock(1, 0);
    if (_windowCheck() || _blockCheck())
    {
      cur.MoveBlock(-1, 0);
      invincibilityFrames++;
      if (invincibilityFrames * tickRate * 3 > 2)
      {
        LockBlock();
        invincibilityFrames = 0; // reset invincibility frames after locking block
      }
      break;
    }
    invincibilityFrames = 0; // reset invincibility frames in case of no collision
    break;
  case 'u':
  {
    std::cout << "rotate :" << std::endl;
    _RotateBlock();
    if (_blockCheck())
    {
      std::cout << "denied" << std::endl;
      _unRotateBlock();
      break;
    }
    break;
  }
  default:
    break;
  }
}

void Game::LockBlock()
{
  std::vector<position> tiles = cur.GetBlockPos();
  for (position item : tiles)
  {
    grid.grid[item.x][item.y] = cur.id;
  }
  cur = next;
  next = GetRandomBlock();
  grid.UpdateGrid();
  std::cout << std::gcd(2, 3);
}

void Game::_kickBack(int from)
{
  cur.KickBack(from);
}

bool Game::
    _blockCheck()
{
  std::vector<position> tiles = cur.GetBlockPos();
  for (position item : tiles)
  {
    if (grid.BlockCheck(item.x, item.y))
    {
      std::cout << "Block Check : " << grid.BlockCheck(item.x, item.y) << std::endl;
      return true;
    }
  }
  return false;
}

int Game::_windowCheck()
{
  std::vector<position> tiles = cur.GetBlockPos();
  for (position item : tiles)
  {
    int overflow = grid.WindowCheck(item.x, item.y);
    if (overflow)
    {
      std::cout << "Window Check : " << grid.WindowCheck(item.x, item.y) << std::endl;
      return overflow;
    }
  }
  return false;
}

void Game::_RotateBlock()
{

  int overflow = 0;
  cur.RotateBlock(); // changed to do while cos I-Block was still overflowing
  do
  {
    overflow = _windowCheck();
    _kickBack(overflow);
  } while (overflow);
}

void Game::_unRotateBlock()
{
  cur.UnRotateBlock();
  // _kickBack(_windowCheck()); // unnecessary check since window check for previos was obviously fine but for security purpose keep
  // remove incase of optimization
}

int main()
{
  Color iLike = {31, 53, 76, 255};
  InitWindow(900, 540, "Hello ,WIZ!!");
  SetTargetFPS(60); // i hope raylib uses delta time appropriately
  Game game = Game();

  while (WindowShouldClose() == false)
  {
    game.HandleInput();
    if (UpdateTick(tickRate))
    {
      game.ControlBlock('d');
    }
    BeginDrawing();
    ClearBackground(iLike);
    game.Draw();
    EndDrawing();
  }

  CloseWindow();
}