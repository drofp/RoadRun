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
};
} // namespace roadrun
#endif
