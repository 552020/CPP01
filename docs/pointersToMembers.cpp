#include <iostream>

class MyClass
{
  public:
	MyClass() : myInt(41) {}
	~MyClass() {}

	int myInt;
	void myFunction() { std::cout << "Hello from myFunction!" << std::endl; }
	void myOtherFunction() { std::cout << "Hello from myOtherFunction!" << std::endl; }
	int getMyPrivateInt() { return myPrivateInt; };

  private:
	int myPrivateInt;
};

int main()
{
	int MyClass::*pointerToMember;
	std::cout << "Adress of pointerToMember: " << &pointerToMember << std::endl;
	std::cout << "Size of pointerToMember: " << sizeof(pointerToMember) << std::endl;
	std::cout << "Pointer to member: " << pointerToMember << std::endl;

	pointerToMember = &MyClass::myInt;
	int (MyClass::*pointerToIntMemberFunction)(void);

	// We define an object of type MyClass
	MyClass myObject;
	std::cout << "myObject.myInt: " << myObject.myInt << std::endl;
	// Assignemen of myInt of myObject through the pointer to member pointerToMember
	myObject.*pointerToMember = 42;
	std::cout << "myObject.myInt: " << myObject.myInt << std::endl;
	// We define a pointer to an object of type MyClass
	MyClass *myObjectPtr = &myObject;
	// We assign to the member myInt of myObject the value 20 through the pointer to member pointerToMember previously
	myObjectPtr->*pointerToMember = 43;
	std::cout << "myObject.myInt: " << myObject.myInt << std::endl;
	// We define a pointer to a member function of MyClass
	void (MyClass::*pointerToMemberFunction)(void);
	pointerToMemberFunction = &MyClass::myFunction;
	std::cout << "Calling myFunction through pointerToMemberFunction" << std::endl;
	(myObject.*pointerToMemberFunction)();
	pointerToMemberFunction = &MyClass::myOtherFunction;
	std::cout << "Calling myOtherFunction through pointerToMemberFunction" << std::endl;
	(myObject.*pointerToMemberFunction)();
	std::cout << "Calling myOtherFunction through myObjectPtr and pointerToMemberFunction" << std::endl;
	(myObjectPtr->*pointerToMemberFunction)();
}