#include "keyboard_listener.h"

int main() 
{
  roadrun::KeyboardListener *p = new roadrun::KeyboardListener();

  p->ListenForKeys();

  delete p;

  return 0;
}
