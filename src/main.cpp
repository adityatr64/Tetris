#include <raylib.h>
#include "grid.h"
#include "ChildBlocks.cpp"
#include "main.h"
#include <random>

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
        RotateBlock(); // rotate
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
        if (windowCheck())
        {
            cur.MoveBlock(0, 1);
        }

        break;
    case 'r':
        cur.MoveBlock(0, 1);
        if (windowCheck())
        {
            cur.MoveBlock(0, -1);
        }
        break;
    case 'd':
        cur.MoveBlock(1, 0);
        if (windowCheck())
        {
            cur.MoveBlock(-1, 0);
        }
        break;
    default:
        break;
    }
}

bool Game::windowCheck()
{
    std::vector<position> tiles = cur.GetBlockPos();
    for (position item : tiles)
    {
        if (grid.WindowCheck(item.x, item.y))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    cur.RotateBlock();
    if (windowCheck())
    {
        cur.RotateBlock();
    }
}

int main()
{
    Color iLike = {26, 27, 38, 255};
    InitWindow(800, 450, "Hello ,WIZ!!");
    SetTargetFPS(60);
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(iLike);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}