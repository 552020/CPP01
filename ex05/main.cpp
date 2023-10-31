#include "Harl.hpp"
#include <iostream>

int main(void) {
  Harl myHarl;
  std::cout << "Using pointer to member function" << std::endl;
  myHarl.complain("DEBUG");
  myHarl.complain("INFO");
  myHarl.complain("WARNING");
  myHarl.complain("ERROR");
  std::cout << std::endl;
  std::cout << "Using if-else" << std::endl;
  myHarl.complain_if_else("DEBUG");
  myHarl.complain_if_else("INFO");
  myHarl.complain_if_else("WARNING");
  myHarl.complain_if_else("ERROR");
  return 0;
}