#include "map_generator_hard.h"

namespace roadrun
{
// May include future support for direction changes
const char* MapGeneratorHard::GenerateMap(char* game_map)
{
  // Create new line to be inserted at top of game_map
  char new_line[kMenuWidth];
  if (ticks % kMillisPerFrameHard == 0)
  {
    GenerateNewLine(new_line);
    MapUpdater::MoveLinesDown(ticks, game_map, new_line);
  }

  ticks = ticks > kMaxTickCnt ? 0 : ++ticks;

  return game_map;
}

void MapGeneratorHard::GenerateNewLine(char* new_line)
{
  int wall_shift = rand() % 2 == 0 ? -1 : 1;
  
  if (split_location_right + wall_shift < kMenuWidth
      && split_location_left + wall_shift > 0)
  {
    split_location_left += wall_shift;
    split_location_right += wall_shift;
  }

  for (int i = 0; i < split_location_left; i++)
  {
    if(rand() % 3 == 0)
      new_line[i] = (char)'O';
    else
      new_line[i] = (char)'#';
  }
  
  for (int i = split_location_left; i < split_location_right; i++)
    new_line[i] = (char)' ';

  for (int i = split_location_right; i < kMenuWidth; i++)
  {
    if(rand() % 3 == 0)
      new_line[i] = (char)'O';
    else
      new_line[i] = (char)'#';
  }
}
} // namespace roadrun
