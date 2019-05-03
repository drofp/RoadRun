#include "game.h"

namespace roadrun
{
Game::Game(int width, int height, char player_icon)
{
  int starty = 0;
  int startx = 0;
  this->height = height;
  this->width = width;

  this->player_icon = player_icon;
  player_locy = (starty + height) - 1;
  player_locx = (startx + width) / 2;
  player_deltax = 0;

  // this->map_generator = MapGeneratorFactory::create();

  initscr();
  clear();
  noecho();
  cbreak(); /* Line buffering disabled. pass on everything */
  curs_set(0); // hide cursor

  game_win = newwin(height, width, starty, startx);
  // cout << "newwin(height, width, starty, startx) = " << "(" << height << 
  //   ", " << width << ", " << starty << ", " << startx << ")" << endl;
  
  nodelay(game_win, true);
  keypad(game_win, true);
  refresh();
}

void Game::PlayGame(SettingsItem difficulty)
{
  bool playing = true;

  while (playing)
  {
    // mvwprintw(game_win, 15, 15, "before key fetch");
    // wrefresh(game_win);

    key = wgetch(game_win);

    playing = key == 'q' ? false : true;

    // mvwprintw(game_win, 15, 15, "after key fetch");
    // wrefresh(game_win);

    UpdatePlayerLoc();

    PrintFrame(game_win, player_locy, player_locx);
  }

  // wclear(game_win);
  wrefresh(game_win);
  endwin();
}

void Game::PrintFrame(WINDOW *game_win, int player_locy, int player_locx)
{
  wmove(game_win, player_locy, 0);
  wclrtoeol(game_win);
  // wclear(game_win);
  mvwprintw(game_win, 15, 15, "player loc x is %d", player_locx);
  mvwprintw(game_win, player_locy, player_locx, "%c", player_icon);

  napms(1);
  wrefresh(game_win);
  
}
void Game::UpdatePlayerLoc()
{
  UpdatePlayerDeltas();

  if (player_locx + player_deltax >= width || player_locx + player_deltax < 0)
  {
    wmove(game_win, 21, 0);
    wclrtoeol(game_win);
    mvwprintw(game_win, 21, 10, "entered! %d", player_deltax);
    player_deltax = 0;
  }

  wmove(game_win, 20, 0);
  wclrtoeol(game_win);
  mvwprintw(game_win, 20, 10, "delta is: %d", player_deltax);
  player_locx += player_deltax;
}

void Game::UpdatePlayerDeltas()
{
  if (key == KEY_LEFT)
  {
    player_deltax--;
    // wmove(game_win, 22, 0);
    // wclrtoeol(game_win);
    // mvwprintw(game_win, 22, 10, "key LEFT, delta: %d", player_deltax);
  }
  else if (key == KEY_RIGHT)
  {
    player_deltax++;
    // wmove(game_win, 22, 0);
    // wclrtoeol(game_win);
    // mvwprintw(game_win, 22, 10, "key RIGHT, delta: %d", player_deltax);
  }
  else
  {
    player_deltax = 0;
    // wmove(game_win, 22, 0);
    // wclrtoeol(game_win);
    // mvwprintw(game_win, 22, 10, "key NONE, delta: %d", player_deltax);
  }
}
} // namespace roadrun
