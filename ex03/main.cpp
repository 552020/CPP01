#include "HumanA.hpp"
#include "HumanB.hpp"
#include "HumanC.hpp"
#include "Weapon.hpp"

int main()
{

	// TODO: read this:
	// https://chat.openai.com/share/28d10123-e5fc-402a-bef9-e8ddc801cff1 above
	// all why we need to
	//  initialize the weapon in the constructor of HumanA as reference and not as
	//  pointer and in the initialization list
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
// Note 1
// Temporary objects in C++ are destroyed at the end of the full expression in which they are created. This means that
// the temporary Weapon object would be destroyed at the end of the statement, not at the end of the block scope.
// Therefore, by the time the execution reaches the next line, the Weapon object to which clubPTR points would already
// have been destroyed, leaving clubPTR dangling and leading to undefined behavior if dereferenced.