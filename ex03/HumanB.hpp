#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
public:
  HumanB(std::string name);
  HumanB(std::string name, Weapon &weapon);
  ~HumanB();

  std::string name;
  // This way the HumanB instance will have a Weapon instance as a member
  //   Weapon weapon;
  // HumanB can be also without a Weapon
  // if the pointer is null, then the HumanB instance will not have a Weapon
  Weapon *weapon;
  void attack();
  // we create the reference on the fly
  void setWeapon(Weapon &weapon);
};

#endif