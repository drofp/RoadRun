#include "keyboard_listener.h"


using namespace std;

const int kWidth = 30;
const int kHeight = 10;

namespace roadrun
{
void KeyboardListener::ListenForKeys()
{
  WINDOW *menu_win;
  int highlight = 1;
  int choice = 0;
  int c;
  initscr();
  clear();
  noecho();
  cbreak();
  int startx = (80 - kWidth) / 2;
  int starty = (80 - kHeight) / 2;
  menu_win = newwin(kHeight, kWidth, starty, startx);
  keypad(menu_win, TRUE);
  mvprintw(0, 0, "Use ^ and v.");
  refresh();
  print_menu(menu_win, highlight);

}

void print_menu(WINDOW *menu_win, int highlight)
{
  char *choices[] = { 
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
  };
  int x, y, i;
  box(menu_win, 0,0);
  for(i = 0; i < n_)
}

}
