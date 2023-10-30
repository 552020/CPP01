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

Zombie *zombieHorde(int N, std::string name) {
  // Allocate memory for an array of N Zombie objects
  Zombie *horde = new Zombie[N];

  // Initialize each zombie with the provided name
  for (int i = 0; i < N; ++i) {
    // this would initialize a new Zombie object on the stack
    // and it would be destroyed at the end of the loop
    // horde[i] = Zombie(name);
    new (&horde[i]) Zombie(name);
  }

  // Return a pointer to the first zombie in the array
  return horde;
}
