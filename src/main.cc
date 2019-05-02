#include <iostream>
#include "game.h"

int main() 
{
  int height = 30;
  int width = 60;
  char player_icon = '^';
  roadrun::Game *g = new roadrun::Game(height, width, player_icon);
  g->PlayGame();
}
