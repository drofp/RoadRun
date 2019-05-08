#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <iostream>

#include <ncurses.h>
#include "map_generator_factory.h"
#include "settings_item.h"
#include "constants.h"

using namespace std;

namespace roadrun
{
class Game
{
public:
  Game(int width, int height, char player_icon, SettingsItem difficulty,
          int *curr_high_score);
  void PlayGame();

  char GetPlayerIcon();
  void SetPlayerIcon();
private:
  WINDOW *game_win;
  WINDOW *info_win;
  char game_map[(kMenuHeight * (kMenuWidth + 1)) + 1];
  SettingsItem curr_difficulty;
  MapGenerator *map_generator;

  bool playing;
  char player_icon;
  int player_locy;
  int player_locx;
  int player_deltax;
  int key;

  int score_timer;
  int *curr_high_score;
  int curr_score;

  void PrintGameFrame(WINDOW *game_win);
  void PrintInfoFrame(WINDOW *info_win);

  void UpdatePlayerLoc();
  void UpdatePlayerDeltas();
  void CheckCollision();
  void UpdateScore();
  void UpdateHighScore();
};
} // namespace roadrun

#endif