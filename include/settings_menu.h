#ifndef SETTINGS_MENU_H_
#define SETTINGS_MENU_H_

#include "menu.h"
#include "settings_item.h"

namespace roadrun 
{
class SettingsMenu : public Menu<SettingsItem>
{
public:
  SettingsMenu() : current_choice(SettingsItem::kRegular) { }
  void PrintMenu();
  SettingsItem GetUserChoice();
private:
  void RenderOptions(WINDOW *menu_win, int highlight);
  SettingsItem current_choice;
};
} // namespace roadrun

#endif
