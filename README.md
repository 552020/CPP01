# CPP_Module_01

## ex00 - BraiiiiiiinnnzzzZ

## ex01 - Moar brainz!

## 02 - HI THIS IS BRAIN

````

## 03 - Unnecessary violence

### Weapon as reference in the initialisation list

Interesting conversation with the model: https://chat.openai.com/share/28d10123-e5fc-402a-bef9-e8ddc801cff1 about why we need to initialize the Weapon in the constructor of HumanA as reference and not as pointer and in the initialisation list. TBH both could be pointers. If we decide to go for the reference in the case of HumanA, which has always a Weapon, then we need to initialise it in the initialisation list.

```cpp
#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

// Note 1 about initialisation list:
HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) { this->_name = name; }

HumanA::~HumanA() {}

void HumanA::attack() { std::cout << this->_name << " attacks with his " << _weapon.getType() << std::endl; }
````

**Why we need an initialisation list here**
A reference is not a standalone object like a pointer or a regular variable. It's just an alias for another object. So when you create a reference, you must immediately make it refer to something. This is unlike a regular variable or a pointer, where you can declare it and assign it a value later.

In the case of HumanA, the reference weapon must be bound to an existing Weapon object as soon as the HumanA object is created. The only way to do this in a constructor is by using an initialization list. If you try to assign a reference in the constructor body (the normal way), you'll get a compilation error because it's already too late; the reference needs to be bound to something during its creation, which happens before the constructor body is executed.

So, in short, when dealing with references as class members, you're compelled to use initialization lists to initialize them. It's not just a stylistic choice or a matter of efficiency (as it often is with regular variables); it's a fundamental requirement of how references work in C++.

### Human C and the club as pointer

`Weapon *clubPTR = &Weapon("crude spiked club");` this would throw an error

```cpp
// third block scope
	{
		Weapon *clubPTR = new Weapon("crude spiked club");
		// Weapon *clubPTR = &Weapon("crude spiked club");
		HumanC jim("Mike");
		jim.attack();
		jim.setWeapon(clubPTR);
		jim.attack();
		clubPTR->setType("some other type of club");
		jim.attack();
		delete clubPTR;
	}
```

Temporary objects in C++ are destroyed at the end of the full expression in which they are created. This means that the temporary Weapon object would be destroyed at the end of the statement, not at the end of the block scope. Therefore, by the time the execution reaches the next line, the Weapon object to which clubPTR points would already have been destroyed, leaving clubPTR dangling and leading to undefined behavior if dereferenced.

## 04 - Sed is for losers

- _File manipulatio_

## Headers

fstream: ifstram, ofstream
iostream: cerr, cout
sstream: ostringstream
string: string

### Note 1 `std::ifstream input_file(path.c_str());`

```c++
	std::ifstream input_file(path.c_str());
	if (!input_file.is_open())
	{
		std::cerr << "Could not open the file - '" << path << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
```

The _c_str()_ function is a member function of the std::string class in C++. It returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the std::string object.

In readFileIntoString c_str() is called on the path variable, which is of type std::string, to convert it to a C-style string since In C++98, the constructor of std::ifstream (input file stream) does not accept a std::string directly. Instead, it expects a `const char*` type, which is the traditional C-style string.

### Note 2 `buffer << input_file.rdbuf();`

```c++
	std::ostringstream buffer;
	buffer << input_file.rdbuf();
```

Other possible syntaxes:

- `std::ostringstream buffer(input_file.rdbuf());`
- `std::ostringstream buffer << input_file.rdbuf();`

Or without std::ostringstram

```c++
std::string buffer;
std::string line;
while (std::getline(input_file, line)) {
	buffer += line + '\n'; // Repeatedly append to the string
}
```

## ex05 - Harl 2.0

- _Pointers to members_

## ex06 - Harl filter

- _Switch statement_
- Enum

```c++
// EnumLevel is a new type
	enum EnumLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		ELSE
	};
// We declare a variable of type EnumLevel
	EnumLevel chosenLevel = DEBUG;
```

```c++
enum EnumName {
    Value1,
    Value2,
    Value3 = 10, // explicitly assigning a value
    Value4 // Value4 will be 11
};
```

In this definition, EnumName is a **new type** that can hold one of the values Value1, Value2, Value3, or Value4. This can be particularly useful for grouping related constants together or for defining a set of valid values for a variable, making the code more intuitive and type-safe compared to using plain integers.
