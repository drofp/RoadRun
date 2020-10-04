#include "map_generator_factory.h"

namespace roadrun
{
MapGenerator* MapGeneratorFactory::create(SettingsItem difficulty)
{
  if (difficulty == SettingsItem::kRegular)
   return new MapGeneratorEasy();
  else if (difficulty == SettingsItem::kLudicrous)
    return new MapGeneratorHard();
}
} // namespace roadrun
