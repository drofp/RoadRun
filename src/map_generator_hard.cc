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

void MapGeneratorHard::GenerateWall(roadrun::WallSide wall_side,
                                    char* new_line,
                                    int wall_edge)
{
  int lower_limit, upper_limit;
  if (wall_side == roadrun::WallSide::kLeft)
  {
    lower_limit = 0;
    upper_limit = wall_edge;
  }
  else
  {
    lower_limit = wall_edge;
    upper_limit = kMenuWidth - 1;
  }

  for (int i = lower_limit; i < upper_limit; i++)
  {
    if (rand() % 3 == 0)
      new_line[i] = (char)'D';
    else
      new_line[i] = (char)'#';
  }
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

  GenerateWall(roadrun::WallSide::kLeft, new_line, split_location_left);

  for (int i = split_location_left; i < split_location_right; i++)
    new_line[i] = (char)' ';

  GenerateWall(roadrun::WallSide::kRight, new_line, split_location_right);
}
}  // namespace roadrun
