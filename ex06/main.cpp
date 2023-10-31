#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Nope! Check usage!" << std::endl;
    std::cout << "Usage: " << argv[0] << " <DEBUG|INFO|WARNING|ERROR>"
              << std::endl;
    return 1;
  }
  std::string level = argv[1];

  // EnumLevel is a new type
  enum EnumLevel { DEBUG, INFO, WARNING, ERROR, ELSE };
  // We declare a variable of type EnumLevel
  EnumLevel chosenLevel = DEBUG;

  if (level == "DEBUG")
    chosenLevel = DEBUG;
  else if (level == "INFO")
    chosenLevel = INFO;
  else if (level == "WARNING")
    chosenLevel = WARNING;
  else if (level == "ERROR")
    chosenLevel = ERROR;
  else
    chosenLevel = ELSE;

  Harl myHarl;
  switch (chosenLevel) {
  case DEBUG:
    std::cout << "[ DEBUG ]" << std::endl;
    myHarl.complain("DEBUG");
    myHarl.complain("INFO");
    myHarl.complain("WARNING");
    myHarl.complain("ERROR");
    break;
  case INFO:
    std::cout << "[ INFO ]" << std::endl;
    myHarl.complain("INFO");
    myHarl.complain("WARNING");
    myHarl.complain("ERROR");
    break;
  case WARNING:
    std::cout << "[ WARNING ]" << std::endl;
    myHarl.complain("WARNING");
    myHarl.complain("ERROR");
    break;
  case ERROR:
    std::cout << "[ ERROR ]" << std::endl;
    myHarl.complain("ERROR");
    break;
  case ELSE:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    break;
  default:
    std::cout << "This should never be the case!" << std::endl;
    break;
  }

  return 0;
}