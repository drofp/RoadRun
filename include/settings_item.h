#ifndef SETTINGS_ITEM_H_
#define SETTINGS_ITEM_H_

#include "string.h"
#include <ostream>

using namespace std;

namespace roadrun
{
enum class SettingsItem
{
  kRegular,
  kLudicrous
};


static const SettingsItem settings_item_list[] =
{
  SettingsItem::kRegular,
  SettingsItem::kLudicrous
};
static const int num_settings_items = 2;
} // namespace roadrun

inline ostream &operator<<(ostream &ostr, const roadrun::SettingsItem option)
{
  switch (option)
  {
    case roadrun::SettingsItem::kRegular:
      ostr << "Regular Mode";
      break;
    case roadrun::SettingsItem::kLudicrous:
      ostr << "Ludicrous Mode";
      break;
    default:
      ostr << "WHAT";
      break;
  }
  return ostr;
}

inline char* SettingToString(char **arr, roadrun::SettingsItem choice)
{
  int mode = static_cast<int>(choice);
  return arr[mode];
}

#endif
