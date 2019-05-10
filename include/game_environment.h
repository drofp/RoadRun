#ifndef GAME_ENVIRONMENT_H_
#define GAME_ENVIRONMENT_H_

#include <termios.h>
#include <iostream>
#include <map>
#include <unordered_map>

#include <ncurses.h>
#include "settings_item.h"
#include "main_menu.h"
#include "settings_menu.h"
#include "game.h"
#include "constants.h"

using namespace std;

namespace roadrun
{
class GameEnvironment
{
public:
  GameEnvironment();
  ~GameEnvironment();
  int PlayGame();
private:
  SettingsItem difficulty;
  MainMenu *main_menu;
  SettingsMenu *settings_menu;
  Game *game;

  map<SettingsItem, int> difficulty_to_high_score;
  int prev_score;
};
} // namespace roadrun
#endif
