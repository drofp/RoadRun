#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <ostream>

using namespace std;

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
} // namespace roadrun

inline ostream &operator<<(ostream &ostr, const roadrun::MenuItem option)
{
  switch (option)
  {
    case roadrun::MenuItem::kStartGame:
      ostr << "Start Game";
      break;
    case roadrun::MenuItem::kChooseDifficulty:
      ostr << "Choose Difficulty";
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

#endif
