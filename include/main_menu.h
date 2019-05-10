#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include <map>

#include "menu.h"
#include "menu_item.h"
#include "settings_item.h"
#include "constants.h"

namespace roadrun
{
class MainMenu : public Menu<MenuItem>
{
public:
  MainMenu(map<SettingsItem, int> &difficulty_to_high_score) : 
                current_choice(MenuItem::kStartGame),
                difficulty_map(&difficulty_to_high_score) {}
  void PrintMenu();
  MenuItem GetUserChoice();
private:
  void RenderOptions(WINDOW *menu_win, int hightlight);
  MenuItem current_choice;

  map<SettingsItem, int> *difficulty_map;
};
} // namespace roadrun

#endif
