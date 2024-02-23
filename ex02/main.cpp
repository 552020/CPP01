#include <iomanip>
#include <iostream>
#include <string>

void printStringRef(const std::string &str) { std::cout << str << std::endl; }
void printStingPtr(const std::string *str) { std::cout << *str << std::endl; }
void changeString(std::string str) { str = "Hello, Change!"; }
void changeStringRef(std::string &str) { str = "Hello, Change!"; }
void changeStingPtr(std::string *str) { *str = "Hello, Change!"; }

void extra_prints()
{
	std::cout << "\nSome more examples\n" << std::endl;
	std::string myString = "Hello, String!";
	std::string &myStringRef = myString;
	std::string *myStringPtr = &myString;
	printStringRef(myString);
	printStringRef(myStringRef);
	printStringRef(*myStringPtr);
	printStingPtr(myStringPtr);
	printStingPtr(&myString);
	printStingPtr(&myStringRef);
}

void extra_changes()
{
	std::cout << "\nSome more examples\n" << std::endl;
	std::string myString = "Hello, String!";
	std::string &myStringRef = myString;
	std::string *myStringPtr = &myString;
	std::cout << "\nChanging the string\n" << std::endl;
	std::cout << "printString(myString);" << std::endl;
	std::cout << "before: " << myString << std::endl;
	changeString(myString);
	std::cout << "after: " << myString << std::endl;
	myString = "Hello, String!";
	std::cout << "printStringRef(myStringRef);" << std::endl;
	std::cout << "before: " << myStringRef << std::endl;
	changeString(myStringRef);
	std::cout << "after: " << myStringRef << std::endl;
	myString = "Hello, String!";
	std::cout << "printStringRef(myStringRef);" << std::endl;
	std::cout << "before: " << myStringRef << std::endl;
	changeStringRef(myStringRef);
	std::cout << "after: " << myStringRef << std::endl;
	std::cout << "printStringRef(myStringRef);" << std::endl;
	std::cout << "before: " << myStringRef << std::endl;
	changeStringRef(myString);
	std::cout << "after: " << myStringRef << std::endl;
	myString = "Hello, String!";
	std::cout << "printStingPtr(myStringPtr);" << std::endl;
	std::cout << "before: " << *myStringPtr << std::endl;
	changeStringRef(myStringRef);
	std::cout << "after: " << *myStringPtr << std::endl;
	myString = "Hello, String!";
	std::cout << "printStingPtr(myStringPtr);" << std::endl;
	std::cout << "before: " << *myStringPtr << std::endl;
	changeStingPtr(myStringPtr);
	std::cout << "after: " << *myStringPtr << std::endl;
}

int main()
{

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	int width = 35;
	// Print the address of the string.
	std::cout << std::left << std::setw(width) << "Address of the string: " << &string << std::endl;
	// Print the value of stringPTR: address of string
	std::cout << std::left << std::setw(width) << "Value of stringPTR: " << stringPTR << std::endl;
	// Print the address of stringPTR: address of stringPTR
	// std::cout << std::left << std::setw(width) << "Address of stringPTR (address): " << &stringPTR << std::endl;
	// Print the address of stringREF.
	std::cout << std::left << std::setw(width) << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << std::left << std::setw(width) << "Value of string: " << string << std::endl;
	std::cout << std::left << std::setw(width) << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	// Print the value of stringREF.
	std::cout << std::left << std::setw(width) << "Value of stringREF: " << stringREF << std::endl;
	// Print the value pointed to by stringREF.
	std::cout << std::left << std::setw(width) << "Value pointed to by stringREF: ";
	std::cout << std::left << std::setw(width)
			  << "stringREF is a reference, not a pointer. It doesn't point to anything" << std::endl;
	std::cout << "... see comments in main.cpp" << std::endl;

	// Uncomment the line below to see the error.
	// std::cout << "Value pointed to by stringREF: " << *stringREF << std::endl;

	// extra_prints();
	// extra_changes();

	return (0);
}
