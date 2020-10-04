#include "settings_menu.h"

namespace roadrun
{
  void SettingsMenu::RenderOptions(WINDOW *menu_win, int highlight)
  {
    mvwprintw(menu_win, 2, 4, "Choose a Difficulty");
    char *choices[] = {
        "Regular Mode",
        "Ludicrous Mode",
        "Ron Mak",
    };
    int x, y, i;
    x = y = 4;
    box(menu_win, 0,0);
    for(i = 0; i < num_settings_items; i++) {
      if(highlight == i + 1)
      {
        wattron(menu_win, A_REVERSE);
        mvwprintw(menu_win, y, x, "%s",
                  SettingToString(choices, settings_item_list[i]));
        wattroff(menu_win, A_REVERSE);
      }
      else
      {
        mvwprintw(menu_win, y, x, "%s",
                  SettingToString(choices, settings_item_list[i]));
      }
      ++y;
    }
  wrefresh(menu_win);
  }

  void SettingsMenu::PrintMenu()
  {
    endwin();
    refresh();
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;
    initscr();
    clear();
    noecho();
    cbreak();
    int startx = 5;  // (80 - kWidth) / 2;
    int starty = 5;  // (80 - kHeight) / 2;
    menu_win = newwin(kHeight, kWidth, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(0, 0, "Use up and down arrows to choose, enter to select.");
    refresh();
    RenderOptions(menu_win, highlight);
    int enter_pressed = 0;
    while(!enter_pressed)
    {
      c = wgetch(menu_win);
      switch (c)
      {
      case KEY_UP:
        if(highlight == 1)
            highlight = 2;
          else
            --highlight;
          break;
      case KEY_DOWN:
        if(highlight == 2)
          highlight = 1;
        else
          ++highlight;
        break;
      case 10:
        choice = highlight;
        enter_pressed = 1;
        break;
      default:
        // mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
        refresh();
        break;
      }
      current_choice = settings_item_list[highlight - 1];
      RenderOptions(menu_win, highlight);
    }
    // mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
    clrtoeol();
    refresh();
    endwin();
  }

  SettingsItem SettingsMenu::GetUserChoice()
  {
    return current_choice;
  }
}  // namespace roadrun
