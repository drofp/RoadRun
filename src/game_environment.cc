#include "game_environment.h"

namespace roadrun
{
  GameEnvironment::GameEnvironment()
  {
    difficulty = SettingsItem::kRegular;
    main_menu = new MainMenu(kMenuWidth, kMenuHeight);
    settings_menu = new SettingsMenu(kMenuWidth, kMenuHeight);

    high_score_easy = 0;
    high_score_hard = 0;
  }

  GameEnvironment::~GameEnvironment()
  {
    delete main_menu;
    delete settings_menu;
  }

  int GameEnvironment::PlayGame()
  {
    while(1)
    {
      main_menu->PrintMenu();
      roadrun::MenuItem meme = main_menu->GetUserChoice();

      if(meme == roadrun::MenuItem::kChooseDifficulty)
      {
        settings_menu->PrintMenu();
        difficulty = settings_menu->GetUserChoice();
      } 
      else if (meme == roadrun::MenuItem::kStartGame)
      {
        if (difficulty == SettingsItem::kRegular)
        {
          game = new Game(kMenuWidth, kMenuHeight, '^', difficulty, 
                          high_score_easy);
          game->PlayGame();
        }
        else if (difficulty == SettingsItem::kLudicrous)
        {
          game = new Game(kMenuWidth, kMenuHeight, '^', difficulty, 
                        high_score_hard);
          game->PlayGame();
        }

        delete game;
      }
      else 
      {
        break;
      }
    }
    return 0;
  }
} // namespace roadrun

