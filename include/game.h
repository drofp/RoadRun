#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <iostream>

#include <ncurses.h>

#include "map_generator_factory.h"

using namespace std;

namespace roadrun
{
class Game
{
public:
  Game(int height, int width, char player_icon);
  void PlayGame();

  char GetPlayerIcon();
  void SetPlayerIcon();
private:
  WINDOW *game_win;
  int height;
  int width;

  char player_icon;
  int player_locy;
  int player_locx;
  int player_deltax;
  int key;

  MapGenerator *map_generator;

  void PrintFrame(WINDOW *game_win, int player_locy, int player_locx);
  void UpdatePlayerLoc();
  void UpdatePlayerDeltas();
  bool kbhit();
};
} // namespace roadrun

#endif