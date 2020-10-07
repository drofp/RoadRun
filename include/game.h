#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

#include <ncurses.h>
#include "map_generator_factory.h"
#include "settings_item.h"
#include "constants.h"

namespace roadrun
{
class Game
{
public:
  Game(int width, int height, char player_icon, SettingsItem difficulty,
          std::map<SettingsItem, int> &difficulty_to_high_score,
          int &prev);
  void PlayGame();

  char GetPlayerIcon();
  void SetPlayerIcon();

  void PrintMap();
private:
  WINDOW *game_win;
  WINDOW *info_win;
  WINDOW *art_win;
  char game_map[(kMenuHeight * (kMenuWidth + 1)) + 1] = "";
  SettingsItem curr_difficulty;
  MapGenerator *map_generator;

  bool playing;
  char player_icon;
  int player_locy;
  int player_locx;
  int player_deltax;
  int key;

  int score_timer;
  int curr_high_score;
  int curr_score;

  void PrintGameFrame();
  void PrintInfoFrame();

  void PrintPrepScreen();
  void PrintEndScreen();

  void UpdatePlayerLoc();
  void UpdatePlayerDeltas();
  void CheckCollision();
  void UpdateScore();
  void UpdateHighScore();

  std::map<SettingsItem, int> *difficulty_map;
  int *prev_score;
};
}  // namespace roadrun

#endif
