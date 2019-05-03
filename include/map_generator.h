#ifndef MAP_GENERATOR_H_
#define MAP_GENERATOR_H_

#include "string.h"

namespace roadrun
{
class MapGenerator
{
public:
  virtual char* GenerateMap() = 0;
};
} // namespace roadrun

#endif
