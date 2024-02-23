#include "HumanC.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanC::HumanC(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}
HumanC::~HumanC() {}

void HumanC::attack()
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

void HumanC::setWeapon(Weapon *weapon) { this->_weapon = weapon; }
