#include "block.h"

// postion (y,x)    ...I'm sorry T-T
// the postions are not in any particular order again
// I'm not very proud of this placements ('owo)/
// Cut me some slack i had to write all of these by hand \(!-!)/
class L_BLOCK : public Block
{
public:
  L_BLOCK()
  {
    id = 1;
    cells[0] = {position(0, 2),
                position(1, 0),
                position(1, 1),
                position(1, 2)};

    cells[1] = {position(0, 1),
                position(1, 1),
                position(2, 1),
                position(2, 2)};

    cells[2] = {position(1, 2),
                position(1, 1),
                position(1, 0),
                position(2, 0)};

    cells[3] = {position(0, 0),
                position(0, 1),
                position(1, 1),
                position(2, 1)};
    MoveBlock(0, 3); // spawn position (i.e. top mid screen)
  }
};

class J_BLOCK : public Block
{
public:
  J_BLOCK()
  {
    id = 2;

    cells[0] = {position(0, 0),
                position(1, 0),
                position(1, 1),
                position(1, 2)};

    cells[1] = {position(0, 1),
                position(1, 1),
                position(2, 1),
                position(0, 2)};

    cells[2] = {position(1, 2),
                position(1, 1),
                position(1, 0),
                position(2, 2)};

    cells[3] = {position(2, 0),
                position(0, 1),
                position(1, 1),
                position(2, 1)};
    MoveBlock(0, 3);
  }
};

class I_BLOCK : public Block
{
public:
  I_BLOCK()
  {
    id = 3;
    cells[0] = {position(1, 3),
                position(1, 0),
                position(1, 1),
                position(1, 2)};

    cells[1] = {position(0, 2),
                position(1, 2),
                position(2, 2),
                position(3, 2)};

    cells[2] = {position(2, 2),
                position(2, 1),
                position(2, 0),
                position(2, 3)};

    cells[3] = {position(3, 1),
                position(0, 1),
                position(1, 1),
                position(2, 1)};
    MoveBlock(-1, 3); // cos this stupis shit spawns it one below???? why???cant be bothered im too cooked rn
  }
};

class O_BLOCK : public Block
{
public:
  O_BLOCK()
  {
    id = 4;
    cells[0] = {position(0, 0),
                position(0, 1),
                position(1, 1),
                position(1, 0)};

    cells[1] = {position(0, 0),
                position(0, 1),
                position(1, 1),
                position(1, 0)};

    cells[2] = {position(0, 0),
                position(0, 1),
                position(1, 1),
                position(1, 0)};

    cells[3] = {position(0, 0),
                position(0, 1),
                position(1, 1),
                position(1, 0)};
    MoveBlock(0, 4); // different spawn position cos centerism
  }
};

class S_BLOCK : public Block
{
public:
  S_BLOCK()
  {
    id = 5;
    cells[0] = {position(1, 1),
                position(1, 0),
                position(0, 1),
                position(0, 2)};

    cells[1] = {position(0, 1),
                position(1, 1),
                position(2, 2),
                position(1, 2)};

    cells[2] = {position(1, 1),
                position(1, 0),
                position(0, 1),
                position(0, 2)};

    cells[3] = {position(0, 1),
                position(1, 1),
                position(2, 2),
                position(1, 2)};
    MoveBlock(0, 3);
  }
};
class T_BLOCK : public Block
{
public:
  T_BLOCK()
  {
    id = 6;

    cells[0] = {position(1, 1),
                position(1, 0),
                position(0, 1),
                position(1, 2)};

    cells[1] = {position(0, 1),
                position(1, 1),
                position(2, 1),
                position(1, 2)};

    cells[2] = {position(1, 1),
                position(1, 2),
                position(1, 0),
                position(2, 1)};

    cells[3] = {position(0, 1),
                position(1, 0),
                position(1, 1),
                position(2, 1)};
    MoveBlock(0, 3);
  }
};

class Z_BLOCK : public Block
{
public:
  Z_BLOCK()
  {
    id = 7;
    cells[0] = {position(1, 1),
                position(0, 0),
                position(0, 1),
                position(1, 2)};

    cells[1] = {position(1, 2),
                position(1, 1),
                position(2, 1),
                position(0, 2)};

    cells[2] = {position(1, 1),
                position(0, 0),
                position(0, 1),
                position(1, 2)};

    cells[3] = {position(1, 2),
                position(1, 1),
                position(2, 1),
                position(0, 2)};
    MoveBlock(0, 3);
  }
};