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

void Harl::complain_if_else(std::string level)
{
	if (level == "DEBUG")
	{
		debug();
	}
	else if (level == "INFO")
	{
		info();
	}
	else if (level == "WARNING")
	{
		warning();
	}
	else if (level == "ERROR")
	{
		error();
	}
}

void Harl::complain_extra(std::string level)
{
	typedef void (Harl::*ptrToMemberFunction)(void);
	// typdef not strictly necessary, but it makes the code more readable
	// void (Harl::*complainFunctions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	ptrToMemberFunction complainFunctions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int nbrOfComplainFunctions = sizeof(complainFunctions) / sizeof(complainFunctions[0]);
	std::string complainLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < nbrOfComplainFunctions; i++)
	{
		if (level == complainLevels[i])
		{
			(this->*complainFunctions[i])();
			break;
		}
	}
	/* Other ways to assign the pointer and call the function*/
	for (int i = 0; i < nbrOfComplainFunctions; i++)
	{
		if (level == complainLevels[i])
		{
			ptrToMemberFunction complainFunctionPtr = complainFunctions[i];
			void (Harl::*complainFunctionAnotherPtr)(void) = complainFunctions[i];
			(this->*complainFunctionPtr)();
			(this->*complainFunctionAnotherPtr)();
			break;
		}
	}
}
