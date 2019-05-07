#include "map_generator_easy.h"

namespace roadrun
{
const char* MapGeneratorEasy::GenerateMap(char * map)
{
  ticks = ticks > kRefreshRate ? 0 : ++ticks;
  
  // Create new line to be inserted at top of map
  char new_line[kMenuWidth];
  for (int i = 0; i < (kMenuWidth - 1) / 3; i++)
  { 
    new_line[i] = (char)'#';
  }

  for (int i = (kMenuWidth - 1) / 3; i < 2 * (kMenuWidth - 1) / 3; i++)
  { 
    new_line[i] = (char)' ';
  }

  for (int i = 2 * (kMenuWidth - 1) / 3; i < (kMenuWidth - 1); i++)
  { 
    new_line[i] = (char)'#';
  }

  new_line[kMenuWidth - 1] = '\n';

  // Move all the current lines down by one row

  /**
   * for i in range(len(lines) - 1, 0, -1):
   *   lines[i] = lines[i - 1]
   * 
   * col by col:
   *   from start of row to end
   *     
   */
  for (int j = kMenuHeight - 1; j > 0; j--) {
    for (int i = 0; i < kMenuWidth; i++) {
      map[(j * kMenuWidth) + i] = map[((j - 1) * (kMenuWidth)) + i];
    }
  }

  // Write the new line to the 0th line of map
  for (int i = 0; i < kMenuWidth; i++) 
  {
    map[i] = new_line[i];
    
  }

  return map;
}
} // namespace roadrun
