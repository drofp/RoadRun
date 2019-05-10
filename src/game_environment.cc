#include "game_environment.h"

namespace roadrun
{
  GameEnvironment::GameEnvironment()
  {
    int init_easy_score = 0;
    int init_hard_score = 0;

    // high_score_easy = &init_easy_score;
    // high_score_hard = &init_hard_score;

    difficulty_to_high_score[SettingsItem::kRegular] = 0;
    difficulty_to_high_score[SettingsItem::kLudicrous] = 0;
    // difficulty_to_high_score.insert(make_pair(SettingsItem::kRegular, 
    //                                   high_score_easy));
    // difficulty_to_high_score.insert(make_pair(SettingsItem::kLudicrous, 
    //                                   high_score_hard));

    for (auto elm : difficulty_to_high_score)
      cout << elm.first << " high score: " << elm.second << endl;
    
    napms(1000);

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
      cout << "difficulty to high score BEFORE: " << difficulty_to_high_score[difficulty] << endl;
      main_menu->PrintMenu();
      cout << "difficulty to high score kinda sorta before: " << difficulty_to_high_score[difficulty] << endl;
      roadrun::MenuItem menu_choice = main_menu->GetUserChoice();
      cout << "menu choice: " << menu_choice << endl;
      cout << "difficulty to high score kinda before: " << difficulty_to_high_score[difficulty] << endl;

      if(menu_choice == roadrun::MenuItem::kChooseDifficulty)
      {
        settings_menu->PrintMenu();
        difficulty = settings_menu->GetUserChoice();
      } 
      else if (menu_choice == roadrun::MenuItem::kStartGame)
      {
        game = new Game(kMenuWidth, kMenuHeight, '^', difficulty, 
                        difficulty_to_high_score);
        game->PlayGame();
        cout << "difficulty to high score: " << difficulty_to_high_score[difficulty] << endl;

        delete game;

        cout << "difficulty to high score after: " << difficulty_to_high_score[difficulty] << endl;
      }
      else 
      {
        break;
      }
    }
    return 0;
  }
} // namespace roadrun

