#include "main_menu.h"

namespace roadrun
{
  void MainMenu::RenderOptions(WINDOW *menu_win, int highlight)
  {
    mvwprintw(menu_win, 2, 4, "Main Menu");
    char *choices[] = {
        "Play Game",
        "Options",
        "Exit",
    };
    int x, y, i;
    x = y = 4;
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
    info_win = newwin(kInfoHeight, kMenuWidth, starty, kMenuWidth+7);

    keypad(menu_win, TRUE);
    mvprintw(0, 0, "Use up and down arrows to choose, enter to select.");
    mvprintw(1, 0, "==================================================");
    mvprintw(2, 0, "To play: Press left and right arrow keys to move.");
    mvprintw(3, 0, "         Dodge the obstacles as long as you can!");
    mvprintw(4, 0, "Your Character: ^");
    mvwprintw(info_win, 0, 0, R"ronmak(
    ____                  ______
   / __ \____  ____ _____/ / __ \__  ______
  / /_/ / __ \/ __ `/ __  / /_/ / / / / __ \
 / _, _/ /_/ / /_/ / /_/ / _, _/ /_/ / / / /
/_/ |_|\____/\__,_/\__,_/_/ |_|\__,_/_/ /_/
              )ronmak");
    refresh();
    RenderOptions(menu_win, highlight);

    mvwprintw(info_win, 7, 0, "Easy High Score: %d",
                            difficulty_map->operator[](SettingsItem::kRegular));
    mvwprintw(info_win, 8, 0, "Hard High Score: %d",
                          difficulty_map->operator[](SettingsItem::kLudicrous));
    mvwprintw(info_win, 9, 0, "Previous Score: %d", *prev_score);
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
        refresh();
        break;
      }
      current_choice = menu_item_list[highlight - 1];
      RenderOptions(menu_win, highlight);
    }

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
}  // namespace roadrun
