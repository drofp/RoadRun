#ifndef SETTINGS_MENU_H_
#define SETTINGS_MENU_H_

#include "menu.h"
#include "settings_item.h"

namespace roadrun 
{
class MainMenu : public Menu<SettingsItem>
{
public:
  SettingsItem PrintMenu();
private:
  SettingsItem current_choice;
};
} // namespace roadrun

#endif
