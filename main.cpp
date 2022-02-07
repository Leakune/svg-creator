#include <iostream>
#include "src/Views/Menu/Menu.cpp"

int main(int argc, char const *argv[])
{
  std::cout << "Hello World!" << std::endl;
  Menu menu = Menu();
  menu.launch();
  return 0;
}