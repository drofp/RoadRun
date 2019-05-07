#ifndef MAP_GENERATOR_HARD_H_
#define MAP_GENERATOR_HARD_H_

#include "map_generator.h"

namespace roadrun
{
class MapGeneratorHard : public MapGenerator
{
public:
  MapGeneratorHard() : ticks(0) { }
  const char* GenerateMap(char * map);
private:
  int ticks;
};
} // namespace roadrun

#endif
