#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "menu.h"
#include "menu_item.h"

namespace roadrun 
{
class MainMenu : public Menu<MenuItem>
{
public:
  MainMenu() : current_choice(MenuItem::kExit) { }
  MenuItem PrintMenu();
private:
  void RenderOptions(int hightlight);
  MenuItem current_choice;
};
} // namespace roadrun

#endif
