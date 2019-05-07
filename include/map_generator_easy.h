#ifndef MAP_GENERATOR_EASY_H_
#define MAP_GENERATOR_EASY_H_

#include "map_generator.h"
// #include "game_environment.h"

namespace roadrun
{
class MapGeneratorEasy : public MapGenerator
{
public:
  MapGeneratorEasy(int width, int height) : ticks(0) { }
  const char* GenerateMap(char * map);
private:
  int ticks;
};
} // namespace roadrun

#endif
