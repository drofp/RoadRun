#include "game_environment.h"

namespace roadrun
{
  GameEnvironment::GameEnvironment()
  {
    difficulty = SettingsItem::kRegular;
    main_menu = new MainMenu(kWidth, kHeight);
    settings_menu = new SettingsMenu(kWidth, kHeight);
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
        roadrun::SettingsItem meme = settings_menu->GetUserChoice();
      } 
      else if (meme == roadrun::MenuItem::kStartGame)
      {
        // go don
      }
      else 
      {
        break;
      }
    }
    return 0;
  }
} // namespace roadrun

