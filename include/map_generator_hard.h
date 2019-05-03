#ifndef MAP_GENERATOR_HARD_H_
#define MAP_GENERATOR_HARD_H_

#include "map_generator.h"

namespace roadrun
{
class MapGeneratorHard : public MapGenerator
{
public:
  char* GenerateMap();
};
} // namespace roadrun

#endif
