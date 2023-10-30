#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
  this->name = name;
  //   this->weapon = &weapon;
}

HumanA::~HumanA() {}

void HumanA::attack() {
  std::cout << this->name << " attacks with his " << weapon.getType()
            << std::endl;
}

// Why we need an initialisation list here
// Here's the key point: A reference is not a standalone object like a pointer
// or a regular variable. It's just an alias for another object. So when you
// create a reference, you must immediately make it refer to something. This is
// unlike a regular variable or a pointer, where you can declare it and assign
// it a value later.

// In the case of HumanA, the reference weapon must be bound to an existing
// Weapon object as soon as the HumanA object is created. The only way to do
// this in a constructor is by using an initialization list. If you try to
// assign a reference in the constructor body (the normal way), you'll get a
// compilation error because it's already too late; the reference needs to be
// bound to something during its creation, which happens before the constructor
// body is executed.

// So, in short, when dealing with references as class members, you're compelled
// to use initialization lists to initialize them. It's not just a stylistic
// choice or a matter of efficiency (as it often is with regular variables);
// it's a fundamental requirement of how references work in C++.
