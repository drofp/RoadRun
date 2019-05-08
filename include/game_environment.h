#ifndef GAME_ENVIRONMENT_H_
#define GAME_ENVIRONMENT_H_

#include <termios.h>
#include <iostream>

#include <ncurses.h>
#include "settings_item.h"
#include "main_menu.h"
#include "settings_menu.h"
#include "game.h"
#include "constants.h"

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
};
} // namespace roadrun
#endif
