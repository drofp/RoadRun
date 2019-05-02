#ifndef MENU_H_
#define MENU_H_

#include <termios.h>
#include <unistd.h>
#include <iostream>

#include <ncurses.h>

namespace roadrun
{
template <typename T>

class Menu
{
public:
  virtual T PrintMenu() = 0;
  const int kHeight = 10;
  const int kWidth = 20;
private:
  virtual void RenderOptions(WINDOW *menu_win, int highlight) = 0;
};
} // namespace roadrun
#endif
