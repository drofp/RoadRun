#include "game_environment.h"

namespace roadrun
{
  GameEnvironment::GameEnvironment()
  {
    difficulty_to_high_score[SettingsItem::kRegular] = 0;
    difficulty_to_high_score[SettingsItem::kLudicrous] = 0;

    difficulty = SettingsItem::kRegular;
    main_menu = new MainMenu(difficulty_to_high_score, prev_score);
    settings_menu = new SettingsMenu(kMenuWidth, kMenuHeight);
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
      roadrun::MenuItem menu_choice = main_menu->GetUserChoice();

      if(menu_choice == roadrun::MenuItem::kChooseDifficulty)
      {
        settings_menu->PrintMenu();
        difficulty = settings_menu->GetUserChoice();
      }
      else if (menu_choice == roadrun::MenuItem::kStartGame)
      {
        game = new Game(kMenuWidth, kMenuHeight, '^', difficulty,
                        difficulty_to_high_score, prev_score);
        game->PlayGame();

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

