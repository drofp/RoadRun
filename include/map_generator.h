#ifndef MAP_GENERATOR_H_
#define MAP_GENERATOR_H_

#include "string.h"
#include <random>

#include "constants.h"

namespace roadrun
{
class MapGenerator
{
public:
  virtual const char* GenerateMap(char * input) = 0;
};
} // namespace roadrun

#endif
