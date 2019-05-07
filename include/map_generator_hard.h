#ifndef MAP_GENERATOR_HARD_H_
#define MAP_GENERATOR_HARD_H_

#include "map_generator.h"

namespace roadrun
{
class MapGeneratorHard : public MapGenerator
{
public:
  MapGeneratorHard(int width, int height) : ticks(0), 
    width(width), height(height) { }
  const char* GenerateMap(char * map);
private:
  int width;
  int height;
  int ticks;
};
} // namespace roadrun

#endif
