#include "map_generator_easy.h"

namespace roadrun
{
const char* MapGeneratorEasy::GenerateMap(char * map)
{
  ticks = ticks > kRefreshRate ? 0 : ++ticks;
  // static char frame[(GameEnvironment::kMenuWidth + 1) * (1GameEnvironment::kMenuHeight) + 1];


  return "easy";
}
} // namespace roadrun
