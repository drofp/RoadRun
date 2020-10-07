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
  MainMenu(std::map<SettingsItem, int> &difficulty_to_high_score, int &prev) :
                current_choice(MenuItem::kStartGame),
                difficulty_map(&difficulty_to_high_score),
                prev_score(&prev) {}
  void PrintMenu();
  MenuItem GetUserChoice();
private:
  void RenderOptions(WINDOW *menu_win, int hightlight);
  MenuItem current_choice;

  std::map<SettingsItem, int> *difficulty_map;
  int *prev_score;
};
}  // namespace roadrun

#endif
