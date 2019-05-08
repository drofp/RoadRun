#ifndef MAP_GENERATOR_EASY_H_
#define MAP_GENERATOR_EASY_H_

#include "map_generator.h"
#include "map_updater.h"

namespace roadrun
{
class MapGeneratorEasy : public MapGenerator
{
public:
  MapGeneratorEasy() : ticks(0) {}
  const char* GenerateMap(char* map);
private:
  int ticks;
  void GenerateNewLine(char* new_line);
};
} // namespace roadrun

#endif
