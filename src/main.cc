#include "game_environment.h"

int main()
{
  roadrun::GameEnvironment *game_environment = new roadrun::GameEnvironment();
  game_environment->PlayGame();

  delete game_environment;
  return 0;
}
