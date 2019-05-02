#include "settings_menu.h"
#include "settings_item.h"

int main() 
{
  roadrun::SettingsMenu *p = new roadrun::SettingsMenu();
  p->PrintMenu();
  return 0;
}
