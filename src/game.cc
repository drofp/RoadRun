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
  curs_set(0); // hide cursor

  game_win = newwin(height, width, starty, startx);
  // cout << "newwin(height, width, starty, startx) = " << "(" << height << 
  //   ", " << width << ", " << starty << ", " << startx << ")" << endl;
  
  // nodelay(stdscr, true);
  nodelay(game_win, true);
  keypad(game_win, true);
  refresh();
}

void Game::PlayGame()
{
  bool playing = true;

  while (playing)
  {
    key = wgetch(game_win);

    switch (key)
    {
    case KEY_LEFT:
      mvwprintw(game_win, 10, 10, "left!");
      wrefresh(game_win);
      // sleep_for(milliseconds(500));
      player_locx--;
      break;
    case KEY_RIGHT:
      mvwprintw(game_win, 10, 10, "right!");
      wrefresh(game_win);
      // sleep_for(milliseconds(500));
      player_locx++;
      break;
    case 'q':
      playing = false;
      mvwprintw(game_win, 10, 10, "quit!");
      wrefresh(game_win);
      // sleep_for(milliseconds(500));
      break;
    default:
      break;
    }

    PrintFrame(game_win, player_locy, player_locx);
  }
  
  // mvprintw(10, 10, "key is %d", key);
  // refresh();
  // sleep_for(milliseconds(2000));
  
  // PrintFrame(game_win, player_locy, player_locx);
  clrtoeol();
  wrefresh(game_win);
  endwin();
}

void Game::PrintFrame(WINDOW *game_win, int player_locy, int player_locx)
{
  wmove(game_win, player_locy, 0);
  wclrtoeol(game_win);
  mvwprintw(game_win, player_locy, player_locx, "%c", player_icon);
  
  wrefresh(game_win);
  // sleep_for(milliseconds(500));
}

} // namespace roadrun
