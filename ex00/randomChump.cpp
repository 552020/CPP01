#include "Zombie.hpp"

// randomChump() implementation
void randomChump(std::string name) {
  Zombie chumpZombie(name);
  chumpZombie.announce();
}
