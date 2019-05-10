#include "main_menu.h"

using namespace std;

namespace roadrun
{
  void MainMenu::RenderOptions(WINDOW *menu_win, int highlight)
  {

    char *choices[] = { 
        "Play Game",
        "Options",
        "Exit",
    };
    int x, y, i;
    x = y = 2;
    box(menu_win, 0,0);
    for(i = 0; i < num_menu_items; i++) {
      if(highlight == i + 1)
      {
        wattron(menu_win, A_REVERSE);
        mvwprintw(menu_win, y, x, "%s", MenuItemToString(choices, menu_item_list[i]));
        wattroff(menu_win, A_REVERSE);
      }
      else
      {
        mvwprintw(menu_win, y, x, "%s", MenuItemToString(choices, menu_item_list[i]));
      }
      ++y;
    }
  wrefresh(menu_win);
  }

  void MainMenu::PrintMenu()
  {

    endwin();
    refresh();
    WINDOW *menu_win;
    WINDOW *info_win;
    
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    
    int startx = 5; //(80 - kWidth) / 2;
    int starty = 5; //(80 - kHeight) / 2;
    
    menu_win = newwin(kMenuHeight, kMenuWidth, starty, startx);
    info_win = newwin(kInfoHeight, kInfoWidth, starty, kMenuWidth+7);
    
    keypad(menu_win, TRUE);
    mvprintw(0, 0, "Use ^ and v.");
    refresh();
    RenderOptions(menu_win, highlight);
    
    mvwprintw(info_win, 0, 0, "Easy High Score: %d",
                            difficulty_map->operator[](SettingsItem::kRegular));
    mvwprintw(info_win, 1, 0, "Hard High Score: %d",
                          difficulty_map->operator[](SettingsItem::kLudicrous));
    mvwprintw(info_win, 2, 0, "Previous Score: %d", *prev_score);
    wrefresh(info_win);

    int enter_pressed = 0;

    while(!enter_pressed)
    {
      c = wgetch(menu_win);
      switch (c)
      {
      case KEY_UP:
        if(highlight == 1)
            highlight = 3;
        else
          --highlight;
          break;
      case KEY_DOWN:
        if(highlight == 3)
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
      current_choice = menu_item_list[highlight - 1];
      RenderOptions(menu_win, highlight);
    }	
    // mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
    // clrtoeol();
    wclear(menu_win);
    clear();
    refresh();
    wrefresh(menu_win);
    endwin();
  }

  MenuItem MainMenu::GetUserChoice()
  {
    return current_choice;
  }
} // namespace roadrun
