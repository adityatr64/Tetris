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
    // idk copilot made this XD
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
        break;

    default:
        break;
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
        BeginDrawing();
        ClearBackground(iLike);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}