#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "menu.h"
#include "menu_item.h"

namespace roadrun 
{
class MainMenu : public Menu<MenuItem>
{
public:
  MainMenu(int width, int height) : current_choice(MenuItem::kStartGame),
    kWidth(width), kHeight(height) { }
  void PrintMenu();
  MenuItem GetUserChoice();
private:
  void RenderOptions(WINDOW *menu_win, int hightlight);
  MenuItem current_choice;
  const int kWidth;
  const int kHeight;
};
} // namespace roadrun

#endif
