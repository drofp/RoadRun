#ifndef MAP_GENERATOR_FACTORY_H_
#define MAP_GENERATOR_FACTORY_H_

#include <string>

#include "map_generator.h"
#include "map_generator_easy.h"
#include "map_generator_hard.h"

namespace roadrun
{
class MapGeneratorFactory
{
public:
  static MapGenerator* create(std::string choice);
};
} // namespace roadrun

#endif
