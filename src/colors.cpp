#include "colors.h"
#include <vector>

const Color gray = {128, 128, 128, 255};
const Color red = {255, 0, 0, 255};
const Color green = {0, 255, 0, 255};
const Color blue = {0, 0, 255, 255};
const Color yellow = {255, 255, 0, 255};
const Color cyan = {0, 255, 255, 255};
const Color magenta = {255, 0, 255, 255};
const Color white = {255, 255, 255, 255};
const Color black = {0, 0, 0, 255};
const Color orange = {255, 165, 0, 255};
const Color purple = {128, 0, 128, 255};
const Color pink = {255, 192, 203, 255};
const Color brown = {165, 42, 42, 255};
const Color lightGreen = {144, 238, 144, 255};
const Color skyBlue = {135, 206, 235, 255};
const Color violet = {238, 130, 238, 255};
const Color teal = {0, 128, 128, 255};
const Color lime = {50, 205, 50, 255};

std::vector<Color> GetColors()
{
  std::vector<Color> colors = {gray, red, green, blue, yellow, cyan, magenta, white, black, orange, purple, pink, brown, lightGreen, skyBlue, violet, teal, lime};
  return colors;
}