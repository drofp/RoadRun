#ifndef DIFFICULTY_MENU_OPTION_H_
#define DIFFICULTY_MENU_OPTION_H_

#include <ostream>

using namespace std;

namespace roadrun
{
enum class DifficultyMenuOption
{
  kRegular,
  kLudicrous
};

static const DifficultyMenuOption difficulty_menu_list[] =
{
  DifficultyMenuOption::kRegular,
  DifficultyMenuOption::kLudicrous
};
static const int num_difficulties = 2;
} // namespace roadrun

inline ostream &operator<<(ostream &ostr, const roadrun::DifficultyMenuOption option)
{
  switch (option)
  {
    case roadrun::DifficultyMenuOption::kRegular:
      ostr << "Regular Mode";
      break;
    case roadrun::DifficultyMenuOption::kLudicrous:
      ostr << "Ludicrous Mode";
      break;
    default:
      ostr << "WHAT";
      break;
  }
  return ostr;
}

#endif
