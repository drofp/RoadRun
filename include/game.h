#ifndef GAME_H_
#define GAME_H_

#include <ncurses.h>

namespace roadrun
{
class Game
{
public:
  Game(int height, int width);
  void PlayGame();

  char GetPlayerIcon();
  void SetPlayerIcon();
private:
  WINDOW *game_win;
  char player_icon;
  int player_loc;
  int key;

  void PrintFrame();
  void UpdatePlayerLoc();
};
} // namespace roadrun

#endif