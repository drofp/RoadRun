#include "game_environment.h"

namespace roadrun
{
  GameEnvironment::GameEnvironment()
  {
    int init_easy_score = 0;
    int init_hard_score = 0;
    // high_score_easy = &init_easy_score;
    // high_score_hard = &init_hard_score;

    difficulty_to_high_score.insert(make_pair(SettingsItem::kRegular, 
                                      &init_easy_score));
    difficulty_to_high_score.insert(make_pair(SettingsItem::kLudicrous, 
                                      &init_hard_score));
    difficulty = SettingsItem::kRegular;
    main_menu = new MainMenu(kMenuWidth, kMenuHeight);
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
      roadrun::MenuItem meme = main_menu->GetUserChoice();

      if(meme == roadrun::MenuItem::kChooseDifficulty)
      {
        settings_menu->PrintMenu();
        difficulty = settings_menu->GetUserChoice();
      } 
      else if (meme == roadrun::MenuItem::kStartGame)
      {
        game = new Game(kMenuWidth, kMenuHeight, '^', difficulty, 
                        difficulty_to_high_score);
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

