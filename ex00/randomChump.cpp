#include "Zombie.hpp"

// randomChump() implementation
void randomChump(std::string name)
{
	std::cout << "We enter the scope of randomChump()" << std::endl;
	std::cout << "We create a Zombie object on the stack." << std::endl;
	Zombie chumpZombie(name);
	std::cout << "The Zombie " << name << " has been created." << std::endl;
	std::cout << "We call the announce() method of the Zombie object.\n" << std::endl;
	chumpZombie.announce();
	std::cout << "\nThe Zombie " << name << " has announced itself." << std::endl;
	std::cout << "We are going to exit the scope of randomChump()" << std::endl;
	std::cout << "The Zombie" << name << " is going to die with its scope." << std::endl;
	std::cout << "Farewell, Zombie " << name << "!" << std::endl;
}
