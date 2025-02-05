#include "Zombie.hpp"

int main()
{
	std::cout << "We enter the scope of main()" << std::endl;
	std::cout << "We create a Zombie object on the heap." << std::endl;
	std::cout << "First we declare a pointer to a Zombie object." << std::endl;
	std::cout << "Then we call the newZombie() function to create a Zombie object." << std::endl;
	std::cout << "We could also have done this in two steps." << std::endl;
	std::string zedName = "Zed";
	Zombie *zedPtr = newZombie(zedName);
	std::cout << "The Zombie" << zedName << " has been created." << std::endl;
	std::cout << "Zed is going to announce itself." << std::endl;
	zedPtr->announce();
	std::cout << zedName << " has announced itself." << std::endl;
	randomChump("Dave");
	std::cout << zedName << " outlived Dave." << std::endl;
	std::cout << "It can now announce itself again." << std::endl;
	zedPtr->announce();
	std::cout << zedName << " has announced itself again." << std::endl;
	std::cout << "But not sadly is going to die." << std::endl;
	// Deleting the dynamically allocated Zombie, will call the destructor
	delete zedPtr;
	std::cout << "Zed is dead." << std::endl;
	std::cout << "If we would not have deleted it, it would have been a memory leak." << std::endl;

	return 0;
}
