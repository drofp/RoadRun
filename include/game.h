#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <iostream>

#include <ncurses.h>
#include "map_generator_factory.h"
#include "settings_item.h"
#include "dimensions.h"

using namespace std;

namespace roadrun
{
class Game
{
public:
  Game(int width, int height, char player_icon);
  void PlayGame(SettingsItem difficulty);

  char GetPlayerIcon();
  void SetPlayerIcon();
private:
  WINDOW *game_win;
  char map[(kMenuHeight * (kMenuWidth + 1)) + 1];

  bool playing;
  char player_icon;
  int player_locy;
  int player_locx;
  int player_deltax;
  int key;

  MapGenerator *map_generator;

  void PrintFrame(WINDOW *game_win, int player_locy, int player_locx);
  void UpdatePlayerLoc();
  void UpdatePlayerDeltas();
  void CheckCollision();
  bool kbhit();
};
} // namespace roadrun

#endif