#include "game.h"

namespace roadrun
{
Game::Game(int height, int width, char player_icon)
{
  int starty = 0;
  int startx = 0;

  this->player_icon = player_icon;

  player_locy = (starty + height) - 1;
  player_locx = (startx + width) / 2;
  cout << "player_locx: " << player_locx << endl;
  cout << "player_locy: " << player_locy << endl;

  initscr();
  clear();
  noecho();
  cbreak(); /* Line buffering disabled. pass on everything */

  game_win = newwin(height, width, starty, startx);
  cout << "newwin(height, width, starty, startx) = " << "(" << height << 
    ", " << width << ", " << starty << ", " << startx << ")" << endl;

  keypad(game_win, TRUE);
  refresh();
}

void Game::PlayGame()
{
  // wattron(game_win, A_NORMAL);
  // wattroff(game_win, A_NORMAL);
  
  PrintFrame(game_win, player_locy, player_locx);
  clrtoeol();
  wrefresh(game_win);
  endwin();
}

void Game::PrintFrame(WINDOW *game_win, int player_locy, int player_locx)
{
  mvwprintw(game_win, player_locy, player_locx, "%c", player_icon);
  // mvwprintw(game_win, player_locx, player_locx, "sah dood^");
  wrefresh(game_win);
  sleep_for(milliseconds(4000));
}

} // namespace roadrun
