#ifndef MAP_UPDATER_H_
#define MAP_UPDATER_H_

#include "constants.h"

namespace roadrun
{
class MapUpdater
{
public:
  static void MoveLinesDown(int ticks, char* game_map, char* new_line);
};
}  // namespace roadrun

#endif
