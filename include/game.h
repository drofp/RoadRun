#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <iostream>

#include <ncurses.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, seconds

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
  char player_icon;
  int player_locy;
  int player_locx;
  int key;

  void PrintFrame(WINDOW *game_win, int player_locy, int player_locx);
  void UpdatePlayerLoc();
};
} // namespace roadrun

#endif