#include <iostream>
#include "game.h"

int main() 
{
  int height = 40;
  int width = 80;
  char player_icon = '^';
  roadrun::Game *g = new roadrun::Game(height, width, player_icon);
  g->PlayGame();
}
