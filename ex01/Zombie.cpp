#include "Zombie.hpp"
#include <iostream>
Zombie::Zombie() : name("Default Scary Name")
{
	std::cout << "Zombie " << name << " created with default constructor." << std::endl;
}
Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie " << name << " created with constructor." << std::endl;
}

Zombie::~Zombie() { std::cout << name << " destroyed." << std::endl; }

void Zombie::announce() const { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::setName(std::string name) { this->name = name; }

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		// Placement new syntax
		new (&horde[i]) Zombie(name);
		// new (horde + i) Zombie(name);
	}

	// Return a pointer to the first zombie in the array
	std::cout << "Zombie horde created." << std::endl;
	return horde;
}

Zombie *anotherZombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		horde[i].setName(name);
		horde[i].announce();
	}

	std::cout << "Another Zombie horde created." << std::endl;
	return horde;
}
