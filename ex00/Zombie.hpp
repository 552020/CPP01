#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
  std::string name;

public:
  // Constructor
  Zombie(std::string name);

  // Destructor
  ~Zombie();

  // Member function to announce
  void announce() const;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif // ZOMBIE_HPP