#include "settings_menu.h"
#include "settings_item.h"
#include "menu_item.h"
#include "main_menu.h"

int main() 
{
  roadrun::MenuItem meme = roadrun::MenuItem::kStartGame;
  
  roadrun::MainMenu *p = new roadrun::MainMenu();
  roadrun::SettingsMenu *d = new roadrun::SettingsMenu();

  // this can change
  while(1)
  {
    p->PrintMenu();
    roadrun::MenuItem meme = p->GetUserChoice();

    std::cout << meme << std::endl;
    sleep(1);
    if(meme == roadrun::MenuItem::kChooseDifficulty)
    {
      d->PrintMenu();
      roadrun::SettingsItem meme = d->GetUserChoice();
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
