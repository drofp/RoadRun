#include "map_generator_factory.h"

namespace roadrun
{
MapGenerator* MapGeneratorFactory::create(string choice)
{
  if (choice == "easy") return new MapGeneratorEasy();
  else if (choice == "hard") return new MapGeneratorHard();
}
} // namespace roadrun
