#ifndef MAP_GENERATOR_FACTORY_H_
#define MAP_GENERATOR_FACTORY_H_

#include "map_generator.h"
#include "map_generator_easy.h"
#include "map_generator_hard.h"

namespace roadrun
{
class MapGeneratorFactory
{
public:
  static MapGenerator* create();
};
} // namespace roadrun

#endif
