#ifndef MAP_GENERATOR_EASY_H_
#define MAP_GENERATOR_EASY_H_

#include "map_generator.h"

namespace roadrun
{
class MapGeneratorEasy : public MapGenerator
{
public:
  MapGeneratorEasy() : ticks(0), millis_per_frame(kMillisPerFrame),
                        millis_per_rock(kMillisPerRock) {}
  const char* GenerateMap(char* map);
private:
  int ticks;
  int millis_per_frame;
  int millis_per_rock;
  // int split_location;
  char* GenerateNewLine(char* new_line);
};
} // namespace roadrun

#endif
