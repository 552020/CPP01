# Pointers to member

Pointers-to-members provide a way to dynamically select a member of a class at runtime. This can be useful for more flexible object manipulation.

## Pointers to function members

```c++
#include <iostream>
#include <string>

class Car {
private: // Data members are now private
    std::string model;
    int year;
    std::string color;

public:
    // Public display functions
    void displayModel() { std::cout << "Model: " << model << std::endl; }
    void displayYear()  { std::cout << "Year: " << year << std::endl; }
    void displayColor() { std::cout << "Color: " << color << std::endl; }
};



void displayCarProperty(const Car& car, void (Car::*propertyPtr)()) {
    (car.*propertyPtr)();
}

int main() {
    Car myCar = {"Mustang", 2020, "red"}; // Data initialization is now done in a constructor (not shown)

	// Declare pointers-to-member-functions separately
	void (Car::*displayModelPtr)() = &Car::displayModel;
	void (Car::*displayYearPtr)()  = &Car::displayYear;
	void (Car::*displayColorPtr)() = &Car::displayColor;

    int choice;
    std::cout << "Select property to display:\n";
    std::cout << "1. Model\n";
    std::cout << "2. Year\n";
    std::cout << "3. Color\n";
    std::cin >> choice;

    switch (choice) {
        case 1: displayCarProperty(myCar, displayModelPtr); break;
        case 2: displayCarProperty(myCar, displayYearPtr);  break;
        case 3: displayCarProperty(myCar, displayColorPtr); break;
        default: std::cout << "Invalid choice\n";
    }


    return 0;
}
```
