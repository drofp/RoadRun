#ifndef START_MENU_OPTION_H_
#define START_MENU_OPTION_H_

#include <ostream>

using namespace std;

namespace roadrun
{
enum class StartMenuOption
{
  kStartGame,
  kChooseDifficulty,
  kExit
};

static const StartMenuOption start_menu_list[] =
{
  StartMenuOption::kStartGame,
  StartMenuOption::kChooseDifficulty,
  StartMenuOption::kExit
};
static const int num_start_options = 3;
} // namespace roadrun

inline ostream &operator<<(ostream &ostr, const roadrun::StartMenuOption option)
{
  switch (option)
  {
    case roadrun::StartMenuOption::kStartGame:
      ostr << "Start Game";
      break;
    case roadrun::StartMenuOption::kChooseDifficulty:
      ostr << "Choose Difficulty";
      break;
    case roadrun::StartMenuOption::kExit:
      ostr << "Exit";
      break;
    default:
      ostr << "WHAT";
      break;
  }
  return ostr;
}

#endif
