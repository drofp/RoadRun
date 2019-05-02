#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "menu.h"
#include "settings_item.h"

namespace roadrun {
class MainMenu
{
public:
  MainMenu();
  void ListenForKeys();
private:
  SettingsItem current_choice;
};
} // namespace roadrun

#endif
