#include <iomanip>
#include <iostream>
#include <string>

void printStringRef(const std::string &str) { std::cout << str << std::endl; }
void printStingPtr(const std::string *str) { std::cout << *str << std::endl; }
// this function will not compile cause of hte const
// void changeString(const std::string str) { str = "Hello, Change!"; }
void changeString(std::string str) { str = "Hello, Change!"; }
void changeStringRef(std::string &str) { str = "Hello, Change!"; }
void changeStingPtr(std::string *str) { *str = "Hello, Change!"; }

int main()
{

	// A string variable initialized to "HI THIS IS BRAIN'
	// in C this would be: char *string = "HI THIS IS BRAIN";
	std::string string = "HI THIS IS BRAIN";

	// stringPTR: A pointer to the string.
	// In C: 	char *stringPTR = &string[0];
	// or: 		char *stringPTR = string;
	std::string *stringPTR = &string;

	// stringREF: A reference to the string.
	// In C we don't have references, so we would use a pointer
	std::string &stringREF = string;

	int width = 35;

	// Print the address of the string.
	std::cout << std::left << std::setw(width) << "Address of the string: " << &string << std::endl;
	// Print the address of stringPTR. Value of stringPTR, address of string
	std::cout << std::left << std::setw(width) << "Address of stringPTR (value): " << stringPTR << std::endl;
	// Print the address of stringPTR. Address of stringPTR
	std::cout << std::left << std::setw(width) << "Address of stringPTR (address): " << &stringPTR << std::endl;
	// Print the address of stringREF.
	std::cout << std::left << std::setw(width) << "Address of stringREF: " << &stringREF << std::endl;

	// Print the value of string.
	std::cout << std::left << std::setw(width) << "Value of string: " << string << std::endl;
	// Print the value pointed to by stringPTR.
	std::cout << std::left << std::setw(width) << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	// Print the value of stringREF.
	std::cout << std::left << std::setw(width) << "Value of stringREF: " << stringREF << std::endl;
	std::cout << std::left << std::setw(width) << "Value pointed to by stringREF: ";
	std::cout << std::left << std::setw(width)
			  << "stringREF is a reference, not a pointer. It doesn't point to anything" << std::endl;

	// Print the value pointed to by stringREF.
	// This line will result in a compilation error because stringREF is a
	// reference, not a pointer. Uncomment the line below to see the error.
	// std::cout << std::left << std::setw(width)
	//           << "Value pointed to by stringREF: " << *stringREF <<
	//           std::endl;

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

	return (0);
}
