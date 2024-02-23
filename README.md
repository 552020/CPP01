# CPP_Module_01

## ex05

## ex06

- switch statement

- enum

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
