#include <iostream>

// Function declaration
int add(int a, int b);

int main() {
  // Function pointer declaration
  int (*functionPtr)(int, int);

  // Assigning the function's address to the pointer
  functionPtr = add;

  // Using the function pointer to call the function
  int result = functionPtr(3, 5);

  std::cout << "Result: " << result << std::endl;

  // Print the address stored in functionPtr
  std::cout << "Address stored in functionPtr: " << functionPtr << std::endl;
  std::cout << "Reinterpreted address stored in functionPtr: "
            << reinterpret_cast<void *>(functionPtr) << std::endl;
  std::cout << "Reinterpreted address stored in functionPtr with &: "
            << &functionPtr << std::endl;

  // Print the address of the function add
  std::cout << "Address of the function add: " << add << std::endl;
  std::cout << "Reinterpreted address of the function add: "
            << reinterpret_cast<void *>(add) << std::endl;
  std::cout << "Reinterpreted address of the function add with &: " << &add
            << std::endl;

  return 0;
}

// Function definition
int add(int a, int b) { return a + b; }
