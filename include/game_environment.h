#ifndef GAME_ENVIRONMENT_H_
#define GAME_ENVIRONMENT_H_

#include <termios.h>
#include <iostream>

#include <ncurses.h>
#include "settings_item.h"
#include "main_menu.h"
#include "settings_menu.h"
#include "game.h"

namespace roadrun
{
class GameEnvironment
{
public:
  // inline static constexpr int kMenuHeight = 10;
  // inline static constexpr int kMenuWidth = 20;
  int kMenuHeight = 10;
  int kMenuWidth = 20;

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
