#ifndef MAP_GENERATOR_EASY_H_
#define MAP_GENERATOR_EASY_H_

#include "map_generator.h"

namespace roadrun
{
class MapGeneratorEasy : public MapGenerator
{
public:
  char* GenerateMap();
};
} // namespace roadrun

#endif
