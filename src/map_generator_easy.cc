#include "map_generator_easy.h"

namespace roadrun
{
const char* MapGeneratorEasy::GenerateMap(char * map)
{
  
  // Create new line to be inserted at top of map
  char new_line[kMenuWidth];
  for (int i = 0; i < (kMenuWidth - 1) / 3; i++)
  {
    if(rand() % 3 == 0)
    {
    new_line[i] = (char)'D';
    }
    else
    {
      new_line[i] = (char)'#';
    }
  }
  
  int i = (kMenuWidth - 1) / 3;
  while (i < 2 * (kMenuWidth - 1) / 3)
  {
    int index = rand() % 20 + 19;
    if (i == index)
    {
      /* 39 is max right, 20 is max left. we are 
      getting a random place to put some rocks */  
      new_line[i] = (char)'*'; 
      new_line[i + 1] = (char)'*';
      new_line[i + 2] = (char)'*';
      i += 3;
    }
    else
    {
      new_line[i] = (char)' ';
      i++;
    }
  }

  for (int i = 2 * (kMenuWidth - 1) / 3; i < (kMenuWidth - 1); i++)
  { 
    if(rand() % 3 == 0)
    {
    new_line[i] = (char)'X';
    }
    else
    {
      new_line[i] = (char)'#';
    }
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
  if (ticks % millis_per_frame == 0)
  {
    for (int j = kMenuHeight - 1; j > 0; j--) {
      for (int i = 0; i < kMenuWidth; i++) {
        map[(j * kMenuWidth) + i] = map[((j - 1) * (kMenuWidth)) + i];
      }
    }
  }

  // Write the new line to the 0th line of map
  for (int i = 0; i < kMenuWidth; i++) 
  {
    map[i] = new_line[i]; 
  }

  ticks = ticks > 2000 ? 0 : ++ticks;

  return map;
}
} // namespace roadrun
