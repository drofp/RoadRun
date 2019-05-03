#include "map_generator_factory.h"

namespace roadrun
{
MapGenerator* MapGeneratorFactory::create()
{
  return new MapGeneratorEasy();
}
} // namespace roadrun
