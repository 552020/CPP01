class MyClass
{
  public:
	int myInt;
};

int main()
{
	int MyClass::*pointerToMember;
	pointerToMember = &MyClass::myInt;

	MyClass myObject;
	myObject.*pointerToMember = 42;

	pointerToMember = &MyClass::
}