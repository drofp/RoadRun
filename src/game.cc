#include "game.h"

namespace roadrun
{
Game::Game(int width, int height, char player_icon, SettingsItem difficulty,
            std::map<SettingsItem, int> &difficulty_to_high_score,
            int &prev)
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
  difficulty_map = &difficulty_to_high_score;
  curr_score = 0;

  prev_score = &prev;

  curr_difficulty = difficulty;

  initscr();
  clear();
  noecho();
  cbreak(); // Line buffering disabled. pass on everything
  curs_set(0); // hide cursor

  game_win = newwin(kMenuHeight, kMenuWidth, starty, startx);
  info_win = newwin(kInfoHeight, kInfoWidth, starty, kMenuWidth);
  art_win = newwin(300, 300, starty, startx);

  nodelay(game_win, true);
  keypad(game_win, true);
  refresh();
}

// Returns true when done
void Game::PlayGame()
{
  this->map_generator = MapGeneratorFactory::create(curr_difficulty);
  PrintPrepScreen();
  while (playing)
  {
    key = wgetch(game_win);
    playing = key == 'q' ? false : true;

    UpdatePlayerLoc();
    PrintGameFrame();
    PrintInfoFrame();
    napms(1);
  }

  UpdateHighScore();

  wrefresh(game_win);
  wrefresh(info_win);
  wclear(game_win);
  wclear(info_win);
  wrefresh(game_win);
  wrefresh(info_win);
  PrintEndScreen();
  endwin();
  delete map_generator;
}

void Game::PrintGameFrame()
{
  wclear(game_win);

  mvwprintw(game_win, 0, 0, "%s", map_generator->GenerateMap(game_map));
  mvwprintw(game_win, player_locy, player_locx, "%c", player_icon);

  CheckCollision();

  wrefresh(game_win);
}

void Game::PrintInfoFrame()
{
  wclear(info_win);

  UpdateScore();
  mvwprintw(info_win, 0, 0, "player loc x is %d", player_locx);
  mvwprintw(info_win, 1, 0, "High score: %d", curr_high_score);
  mvwprintw(info_win, 2, 0, "Score: %d", curr_score);
  mvwprintw(info_win, 3, 0, "Press 'q' at any time to quit");

  wrefresh(info_win);
}

void Game::PrintPrepScreen()
{
  char* mode;
  const char* kStartArt = R"ronmak(
   / __ \___  ____ _____/ __  __   / /_____     / __ \____  ____ _____/ _______  ______  / /
  / /_/ / _ \/ __ `/ __  / / / /  / __/ __ \   / /_/ / __ \/ __ `/ __  / ___/ / / / __ \/ /
 / _, _/  __/ /_/ / /_/ / /_/ /  / /_/ /_/ /  / _, _/ /_/ / /_/ / /_/ / /  / /_/ / / / /_/
/_/ |_|\___/\__,_/\__,_/\__, /   \__/\____/  /_/ |_|\____/\__,_/\__,_/_/   \__,_/_/ /_(_)
                       /____/
              )ronmak";
if(curr_difficulty == SettingsItem::kRegular)
{

  mode = R"ronmak(
    ______                    __  ___          __
   / ________ ________  __   /  |/  ____  ____/ ___
  / __/ / __ `/ ___/ / / /  / /|_/ / __ \/ __  / _ \
 / /___/ /_/ (__  / /_/ /  / /  / / /_/ / /_/ /  __/
/_____/\__,_/____/\__, /  /_/  /_/\____/\__,_/\___/
                 /____/
              )ronmak";
}
else
{
  mode = R"ronmak(
    __  __               __   __  ___          __
   / / / ____ __________/ /  /  |/  ____  ____/ ___
  / /_/ / __ `/ ___/ __  /  / /|_/ / __ \/ __  / _ \
 / __  / /_/ / /  / /_/ /  / /  / / /_/ / /_/ /  __/
/_/ /_/\__,_/_/   \__,_/  /_/  /_/\____/\__,_/\___/
              )ronmak";
}

  mvwprintw(art_win, 0, 0, "%s", kStartArt);
  mvwprintw(art_win, 10, 0, "%s", mode);
  wrefresh(art_win);
  napms(2000);
  wmove(art_win, 0, 0);
  wclrtobot(art_win);
  wrefresh(art_win);
}

void Game::PrintEndScreen()
{

  const char* kEndArt = R"ronmak(
   ______                        ____                  __
  / ________ _____ ___  ___     / __ \_   _____  _____/ /
 / / __/ __ `/ __ `__ \/ _ \   / / / | | / / _ \/ ___/ /
/ /_/ / /_/ / / / / / /  __/  / /_/ /| |/ /  __/ /  /_/
\____/\__,_/_/ /_/ /_/\___/   \____/ |___/\___/_/  (_)
              )ronmak";
  mvwprintw(art_win, 0, 0, "%s", kEndArt);
  mvwprintw(art_win, 10, 0, "Your score was %d", curr_score);
  wrefresh(art_win);
  napms(2000);
  wclrtobot(art_win);
  wrefresh(art_win);
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
  if (curr_score > curr_high_score)
    difficulty_map->operator[](curr_difficulty) = curr_score;


  *prev_score = curr_score;

  wclear(info_win);
  mvwprintw(info_win, 7, 0, "high score: %d", curr_high_score);
  mvwprintw(info_win, 8, 0, "difficulty_map difficulty: %d", difficulty_map->at(curr_difficulty));

  wrefresh(info_win);

}

}  // namespace roadrun
