#include "map_generator_factory.h"

namespace roadrun
{
MapGenerator* MapGeneratorFactory::create(SettingsItem difficulty, int width, int height)
{
  if (difficulty == SettingsItem::kRegular)
   return new MapGeneratorEasy(width, height);
  else if (difficulty == SettingsItem::kLudicrous) 
    return new MapGeneratorHard(width, height);
}
} // namespace roadrun
