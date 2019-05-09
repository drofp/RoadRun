#include "game.h"

namespace roadrun
{
Game::Game(int width, int height, char player_icon, SettingsItem difficulty,
            map<SettingsItem, int*> difficulty_to_high_score)
{
  int starty = 0;
  int startx = 0;

  playing = true;
  this->player_icon = player_icon;
  player_locy = (starty + height) - 2;
  player_locx = (startx + width) / 2;
  player_deltax = 0;

  score_timer = 0;
  curr_high_score = difficulty_to_high_score[difficulty];
  themap = difficulty_to_high_score;
  curr_score = 0;

  
  for (auto elm : difficulty_to_high_score)
    cout << "====== " << elm.first << " high score: " << *elm.second << endl;

  curr_difficulty = difficulty;

  initscr();
  clear();
  noecho();
  cbreak(); /* Line buffering disabled. pass on everything */
  curs_set(0); // hide cursor

  game_win = newwin(kMenuHeight, kMenuWidth, starty, startx);
  info_win = newwin(kInfoHeight, kInfoWidth, starty, kMenuWidth);

  nodelay(game_win, true);
  keypad(game_win, true);
  refresh();
}

// Returns true when done
void Game::PlayGame()
{
  this->map_generator = MapGeneratorFactory::create(curr_difficulty);

  while (playing)
  {
    key = wgetch(game_win);
    playing = key == 'q' ? false : true;

    UpdatePlayerLoc();

    PrintGameFrame(game_win);
    PrintInfoFrame(info_win);
    napms(1);
  }

  UpdateHighScore();

  wrefresh(game_win);
  wrefresh(info_win);
  endwin();
}

void Game::PrintGameFrame(WINDOW *game_win)
{  
  wclear(game_win);
  
  mvwprintw(game_win, 0, 0, "%s", map_generator->GenerateMap(game_map));
  mvwprintw(game_win, player_locy, player_locx, "%c", player_icon);

  CheckCollision();

  wrefresh(game_win);
}

void Game::PrintInfoFrame(WINDOW *info_win)
{
  wclear(info_win);

  UpdateScore();
  mvwprintw(info_win, 0, 0, "player loc x is %d", player_locx);
  mvwprintw(info_win, 1, 0, "High score: %d", *curr_high_score);
  mvwprintw(info_win, 2, 0, "Score: %d", curr_score);

  wrefresh(info_win);
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

  if (game_map[player_loc] == '*' || game_map[player_loc] == '#')
    playing = false;
}

void Game::UpdateScore()
{
  score_timer++;

  if (score_timer == kScoreTickCnt)
  {
    curr_score++;
    score_timer = 0;
  }
}

void Game::UpdateHighScore()
{
  if (curr_score > *curr_high_score)
    *curr_high_score = curr_score;
  
  wclear(info_win);
  mvwprintw(info_win, 7, 0, "high score: %d", *curr_high_score);
  mvwprintw(info_win, 8, 0, "themap difficulty: %d", *themap[curr_difficulty]);
  wrefresh(info_win);
  napms(1000);
}

} // namespace roadrun
