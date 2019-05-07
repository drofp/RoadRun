#ifndef MAP_GENERATOR_FACTORY_H_
#define MAP_GENERATOR_FACTORY_H_

#include <string>

#include "map_generator.h"
#include "map_generator_easy.h"
#include "map_generator_hard.h"
#include "settings_item.h"

namespace roadrun
{
class MapGeneratorFactory
{
public:
  static MapGenerator* create(SettingsItem difficulty, int width, int height);
};
} // namespace roadrun

#endif
