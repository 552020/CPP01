#include "Zombie.hpp"

#define N 7
int main()
{

	Zombie *horde = zombieHorde(N, "Bub");

	for (int i = 0; i < N; ++i)
	{
		std::cout << "Zombie " << i + 1 << " says: ";
		horde[i].announce();
	}
	delete[] horde;

	Zombie *anotherHorde = zombieHorde(N, "Bob");

	return 0;
}
