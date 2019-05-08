#include "map_generator_easy.h"

namespace roadrun
{
const char* MapGeneratorEasy::GenerateMap(char* game_map)
{
  // Create new line to be inserted at top of game_map
  char new_line[kMenuWidth];
  if (ticks % kMillisPerFrameEasy == 0)
  {
    GenerateNewLine(new_line);
    MapUpdater::MoveLinesDown(ticks, game_map, new_line);
  }

  ticks = ticks > kMaxTickCnt ? 0 : ++ticks;

  return game_map;
}

void MapGeneratorEasy::GenerateNewLine(char* new_line)
{
  // Generate left wall
  for (int i = 0; i < (kMenuWidth - 1) / 3; i++)
  {
    if(rand() % 3 == 0)
      new_line[i] = (char)'D';
    else
      new_line[i] = (char)'#';
  }
  
  // Generate rocks without delay
  // int i = (kMenuWidth - 1) / 3;
  // while (i < 2 * (kMenuWidth - 1) / 3)
  // {
  //   int index = rand() % 20 + 19;
  //   if (i == index)
  //   {
  //     /* 39 is max right, 20 is max left. we are 
  //     getting a random place to put some rocks */
  //     new_line[i] = (char)'*'; 
  //     new_line[i + 1] = (char)'*';
  //     new_line[i + 2] = (char)'*';
  //     i += 3;
  //   }
  //   else
  //   {
  //     new_line[i] = (char)' ';
  //     i++;
  //   }
  // }

  // Generate rocks with delay
  if (ticks % kMillisPerRock == 0)
  {
    int i = (kMenuWidth - 1) / 3;
    int index = rand() % 20 + 18;
    while (i < 2 * (kMenuWidth - 1) / 3)
    {
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
  }
  else
  {
    for (int i = (kMenuWidth - 1) / 3; i < 2 * (kMenuWidth - 1) / 3; i++)
    { 
      new_line[i] = (char)' ';
    } 
  }
  
  // Generate right wall
  for (int i = 2 * (kMenuWidth - 1) / 3; i < (kMenuWidth - 1); i++)
  { 
    if(rand() % 3 == 0)
      new_line[i] = (char)'D';
    else
      new_line[i] = (char)'#';
  }

  new_line[kMenuWidth - 1] = '\n';
}
} // namespace roadrun
