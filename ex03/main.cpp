#include "HumanA.hpp"
#include "HumanB.hpp"
#include "HumanC.hpp"
#include "Weapon.hpp"

int main()
{

	// first block scope
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	// second block scope
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	// third block scope
	{
		Weapon *clubPTR = new Weapon("crude spiked club");
		// Note 1
		// Weapon *clubPTR = &Weapon("crude spiked club");
		HumanC jim("Mike");
		jim.attack();
		jim.setWeapon(clubPTR);
		jim.attack();
		clubPTR->setType("some other type of club");
		jim.attack();
		delete clubPTR;
	}

	return (0);
}
