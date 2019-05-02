#include "settings_menu.h"
#include "settings_item.h"
#include "main_menu.h"

int main() 
{
  roadrun::MainMenu *p = new roadrun::MainMenu();
  p->PrintMenu();
  return 0;
}
