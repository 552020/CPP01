#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
  this->name = name;
  this->weapon = NULL;
}
// this & is the reference of the weapon
HumanB::HumanB(std::string name, Weapon &weapon) {
  this->name = name;
  // this & is the address of the weapon
  this->weapon = &weapon;
}
HumanB::~HumanB() {}

void HumanB::attack() {
  if (weapon) {
    std::cout << this->name << " attacks with his " << this->weapon->getType()
              << std::endl;
  } else {
    std::cout << this->name << " attacks with no weapon!" << std::endl; //
  }
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
