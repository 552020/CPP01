#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}
HumanB::HumanB(std::string name, Weapon &weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}
HumanB::~HumanB() {}

void HumanB::attack()
{
	if (_weapon)
	{
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->_name << " attacks with no weapon!" << std::endl; //
	}
}
// Only HumandB has a setWeapon method that takes a Weapon reference
// This is not defined explicetly in the subject, but we see it in the example
void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
