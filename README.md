# CPP_Module_01

## ex00 - BraiiiiiiinnnzzzZ

## ex01 - Moar brainz!

## 02 - HI THIS IS BRAIN

## 03 - Unnecessary violence

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
