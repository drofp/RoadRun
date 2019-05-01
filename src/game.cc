#include "game.h"

namespace roadrun
{
Game::Game(int height, int width)
{
  int starty = 0;
  int startx = 0;

  initscr();
  clear();
  noecho();
  cbreak(); /* Line buffering disabled. pass on everything */

  game_win = newwin(height, width, starty, startx);
}

void Game::PlayGame()
{
  //
}

void Game::PrintFrame()
{
  //
}

} // namespace roadrun
