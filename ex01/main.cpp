#include "Zombie.hpp"

int main() {

  Zombie *horde = zombieHorde(5, "Bub");
  // Announce each zombie
  for (int i = 0; i < 5; ++i) {
    std::cout << "Zombie " << i + 1 << " says: ";
    horde[i].announce();
  }
  // Delete the array
  delete[] horde;

  return 0;
}
