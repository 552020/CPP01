#include <iomanip>
#include <iostream>
#include <string>

int main() {

  // A string variable initialized to "HI THIS IS BRAIN
  std::string string = "HI THIS IS BRAIN";

  // stringPTR: A pointer to the string.
  //   char *stringPTR = &string[0];
  std::string *stringPTR = &string;

  // stringREF: A reference to the string.
  std::string &stringREF = string;

  int width = 35;

  // Print the address of the string.
  std::cout << std::left << std::setw(width)
            << "Address of the string: " << &string << std::endl;
  // Print the address of stringPTR. Value of stringPTR, address of string
  std::cout << std::left << std::setw(width)
            << "Address of stringPTR (value): " << stringPTR << std::endl;
  // Print the address of stringPTR. Address of stringPTR
  std::cout << std::left << std::setw(width)
            << "Address of stringPTR (address): " << &stringPTR << std::endl;
  // Print the address of stringREF.
  std::cout << std::left << std::setw(width)
            << "Address of stringREF: " << &stringREF << std::endl;

  // Print the value of string.
  std::cout << std::left << std::setw(width) << "Value of string: " << string
            << std::endl;
  // Print the value pointed to by stringPTR.
  std::cout << std::left << std::setw(width)
            << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
  // Print the value of stringREF.
  std::cout << std::left << std::setw(width)
            << "Value of stringREF: " << stringREF << std::endl;
  std::cout << std::left << std::setw(width)
            << "Value pointed to by stringREF: ";
  std::cout
      << std::left << std::setw(width)
      << "stringREF is a reference, not a pointer. It doesn't point to anything"
      << std::endl;

  // Print the value pointed to by stringREF.
  // This line will result in a compilation error because stringREF is a
  // reference, not a pointer. Uncomment the line below to see the error.
  // std::cout << std::left << std::setw(width)
  //           << "Value pointed to by stringREF: " << *stringREF <<
  //           std::endl;

  return (0);
}
