#ifndef MAP_GENERATOR_EASY_H_
#define MAP_GENERATOR_EASY_H_

#include "map_generator.h"
// #include "game_environment.h"

namespace roadrun
{
class MapGeneratorEasy : public MapGenerator
{
public:
  MapGeneratorEasy() : ticks(0), millis_per_frame(50) { }
  const char* GenerateMap(char * map);
private:
  int ticks;
  int millis_per_frame;
  // int split_location;
};
} // namespace roadrun

#endif
