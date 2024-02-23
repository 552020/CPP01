#ifndef HUMANC_HPP
#define HUMANC_HPP

#include "Weapon.hpp"
#include <string>

class HumanC
{
  public:
	HumanC(std::string name);
	HumanC(std::string name, Weapon *weapon);
	~HumanC();
	void attack();
	void setWeapon(Weapon *weapon);

  private:
	std::string _name;
	Weapon *_weapon;
};

#endif