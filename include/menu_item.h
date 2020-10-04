#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <ostream>

namespace roadrun
{
enum class MenuItem
{
  kStartGame,
  kChooseDifficulty,
  kExit
};

static const MenuItem menu_item_list[] =
{
  MenuItem::kStartGame,
  MenuItem::kChooseDifficulty,
  MenuItem::kExit
};
static const int num_menu_items = 3;
}  // namespace roadrun

inline std::ostream &operator<<(std::ostream &ostr,
                                const roadrun::MenuItem option)
{
  switch (option)
  {
    case roadrun::MenuItem::kStartGame:
      ostr << "Start Game";
      break;
    case roadrun::MenuItem::kChooseDifficulty:
      ostr << "Options";
      break;
    case roadrun::MenuItem::kExit:
      ostr << "Exit";
      break;
    default:
      ostr << "WHAT";
      break;
  }
  return ostr;
}

inline char* MenuItemToString(char **arr, roadrun::MenuItem choice)
{
  int mode = static_cast<int>(choice);
  return arr[mode];
}

#endif
