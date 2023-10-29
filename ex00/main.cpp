#include "Zombie.hpp"

int main() {
  Zombie *zedPtr = newZombie("Zed");
  zedPtr->announce();
  delete zedPtr; // Deleting the dynamically allocated Zombie, will call the
                 // destructor

  randomChump("Dave");

  return 0;
}
