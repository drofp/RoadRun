#ifndef MAP_GENERATOR_HARD_H_
#define MAP_GENERATOR_HARD_H_

#include "map_generator.h"
#include "map_updater.h"

namespace roadrun
{
class MapGeneratorHard : public MapGenerator
{
public:
  MapGeneratorHard() : ticks(0), split_location_left(kMenuWidth / 3),
                        split_location_right(2 * kMenuWidth / 3) {}
  const char* GenerateMap(char* game_map);
private:
  int ticks;
  int split_location_left;
  int split_location_right;
  void GenerateNewLine(char* new_line);
};
} // namespace roadrun

#endif
