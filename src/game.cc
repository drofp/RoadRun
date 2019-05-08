#include "game.h"

namespace roadrun
{
Game::Game(int width, int height, char player_icon)
{
  int starty = 0;
  int startx = 0;

  playing = true;
  this->player_icon = player_icon;
  player_locy = (starty + height) - 2;
  player_locx = (startx + width) / 2;
  player_deltax = 0;

  initscr();
  clear();
  noecho();
  cbreak(); /* Line buffering disabled. pass on everything */
  curs_set(0); // hide cursor

  game_win = newwin(kMenuHeight, kMenuWidth, starty, startx);
  // cout << "newwin(height, width, starty, startx) = " << "(" << height << 
  //   ", " << width << ", " << starty << ", " << startx << ")" << endl;
  
  nodelay(game_win, true);
  keypad(game_win, true);
  refresh();
}

// Returns true when done
void Game::PlayGame(SettingsItem difficulty)
{
  curr_difficulty = difficulty;
  this->map_generator = MapGeneratorFactory::create(curr_difficulty);

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
  // wclrtoeol(game_win);
  wclear(game_win);
  mvwprintw(game_win, 0, 0, "%s", map_generator->GenerateMap(game_map));
  mvwprintw(game_win, 25, 0, "player loc x is %d", player_locx);
  mvwprintw(game_win, player_locy, player_locx, "%c", player_icon);

  CheckCollision();

  napms(1);
  wrefresh(game_win);
}

void Game::UpdatePlayerLoc()
{
  UpdatePlayerDeltas();

  if (player_locx + player_deltax >= kMenuWidth 
      || player_locx + player_deltax < 0)
    player_deltax = 0;

  player_locx += player_deltax;
}

void Game::UpdatePlayerDeltas()
{
  if (curr_difficulty == SettingsItem::kRegular)
  {
    if (key == KEY_LEFT)
      player_deltax -= kDeltaEasy;
    else if (key == KEY_RIGHT)
      player_deltax += kDeltaEasy;
    else
      player_deltax = 0;
  }
  else if (curr_difficulty == SettingsItem::kLudicrous)
  {
    if (key == KEY_LEFT)
      player_deltax -= kDeltaHard;
    else if (key == KEY_RIGHT)
      player_deltax += kDeltaHard;
    else
      player_deltax = 0;
  }
}

void Game::CheckCollision()
{
  int player_loc = (player_locy * kMenuWidth) + player_locx;
  // mvwprintw(game_win, 27, 0, "player loc is %c", game_map[player_loc]);

  if (game_map[player_loc] == '*' || game_map[player_loc] == '#')
    playing = false;
}
} // namespace roadrun
