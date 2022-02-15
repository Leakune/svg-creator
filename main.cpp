#include <iostream>
#include "src/Views/Menu/Menu.h"

int main(int argc, char const *argv[])
{
  std::cout << "Launching the app..." << std::endl;

  Menu menu = Menu();
  menu.launch();

  return 0;
}