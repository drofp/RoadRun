#include <iostream>
#include <ctime>

int main() 
{
  int count = 0;
  int start = std::time(nullptr);

  while(std::time(nullptr) != start + 1)
  {
    std::cout << count++ << std::endl;
  }
    std::cout << "Hello Easy C++ project!" << std::endl;
}
