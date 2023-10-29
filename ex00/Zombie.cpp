#include "Zombie.hpp"
#include <iostream>

// Constructor implementation
Zombie::Zombie(std::string name) : name(name) {}

// Destructor implementation
Zombie::~Zombie() { std::cout << name << " destroyed." << std::endl; }

// announce() implementation
void Zombie::announce() const {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
