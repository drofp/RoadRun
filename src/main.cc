#include "game_environment.h"

int main() 
{
  roadrun::GameEnvironment *game = new roadrun::GameEnvironment();
  game->PlayGame();

  delete game;
  return 0;
}
