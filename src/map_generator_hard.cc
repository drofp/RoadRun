#include "map_generator_hard.h"

namespace roadrun
{
const char* MapGeneratorHard::GenerateMap(char * map)
{
  ticks = ticks > kRefreshRate ? 0 : ++ticks;
  return "hard";
}
} // namespace roadrun
