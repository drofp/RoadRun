#ifndef KEYBOARD_LISTENER_H_
#define KEYBOARD_LISTENER_H_

#include <termios.h>
#include <iostream>

#include <ncurses.h>

namespace roadrun {
class KeyboardListener
{
public:
  KeyboardListener() : up_count(0), down_count(0), left_count(0), right_count(0) { }
  void ListenForKeys();
private:
  int up_count;
  int down_count;
  int left_count;
  int right_count;
};
}

#endif
