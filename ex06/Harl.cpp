#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t "
				 "put enough! If you did I would not have to ask for it!"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been "
				 "coming here for years and you just started working here last month."
			  << std::endl;
}

void Harl::error(void) { std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl; }
void Harl::complain(std::string level)
{
	int nbrOfComplainFunctions = 4;
	typedef void (Harl::*ptrToMemberFunction)(void);
	// void (Harl::*complainFunctions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	ptrToMemberFunction complainFunctions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complainLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < nbrOfComplainFunctions; i++)
	{
		if (level == complainLevels[i])
		{
			(this->*complainFunctions[i])();
			break;
		}
	}
}
