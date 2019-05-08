#include "map_updater.h"

namespace roadrun
{
// Move all lines in the map down by 1 row.
// Starts replacing lines from the bottom up.
void MapUpdater::MoveLinesDown(int ticks, char* game_map, char* new_line)
{
  for (int j = kMenuHeight - 1; j > 0; j--) {
    for (int i = 0; i < kMenuWidth; i++) {
      game_map[(j * kMenuWidth) + i] = game_map[((j - 1) * (kMenuWidth)) + i];
    }
  }

  // Write the new line to the 0th line of game_map
  for (int i = 0; i < kMenuWidth; i++)
  {
    game_map[i] = new_line[i];
  }
}
} // namespace roadrun
