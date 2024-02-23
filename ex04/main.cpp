#include <fstream>	// ifstream, ofstream
#include <iostream> // cerr, cout
#include <sstream>	// ostringstream
#include <string>	// getline, string

std::string readFileIntoString(const std::string &path)
{
	// Note 1
	std::ifstream input_file(path.c_str());
	// Note 2
	if (!input_file.is_open())
	{
		std::cerr << "Could not open the file - '" << path << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
	// Note 3
	std::ostringstream buffer;
	buffer << input_file.rdbuf();
	// The same like (but this is more efficient)
	// std::ostringstream buffer(input_file.rdbuf());
	// Or the same like
	// std::ostringstream buffer << input_file.rdbuf();
	input_file.close();
	return (buffer.str());
}

void writeStringIntoFile(const std::string &path, const std::string &content)
{
	std::ofstream output_file(path.c_str());
	if (!output_file.is_open())
	{
		std::cerr << "Could not open the file - '" << path << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
	output_file << content;
	output_file.close();
}

// In C we would use the function strstr to find the first occurrence of a substring in a string.
std::string replaceOccurences(std::string fileContent, const std::string toReplace, const std::string replacer)
{
	size_t pos = 0;
	size_t toReplaceLength = toReplace.length();
	size_t replacerLength = replacer.length();
	while ((pos = fileContent.find(toReplace, pos)) != std::string::npos)
	{
		std::string strBefore = fileContent.substr(0, pos);
		std::string strAfter = fileContent.substr(pos + toReplaceLength);
		fileContent = strBefore + replacer + strAfter;
		// The serarch should continue after the replaced string
		pos += replacerLength;
	}
	return (fileContent);
}

// TODO: think about edge cases
// - s1 and s2 can't be NULL
// - s1 and s2 can be empty strings
// - s1 and s2 can be the same string

void checks(std::string &s1, std::string &s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error! The strings can't be empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (s1 == s2)
	{
		std::cerr << "Error! The strings are the same. Nothing to do!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{

	std::ifstream infile;
	std::string new_content;

	if (argc != 4)
	{
		std::cerr << "Error! " << argc << std::endl;
		std::cerr << "Usage: " << argv[0] << " <file_path> <string_to_replace> <replacement_string>" << std::endl;
		return 1;
	}
	std::string file_path = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	checks(s1, s2);
	std::string content = readFileIntoString(file_path);
	new_content = replaceOccurences(content, s1, s2);
	std::cout << new_content << std::endl;
	writeStringIntoFile(file_path + ".replace", new_content);
}

// Note 1
/*
The c_str() function is a member function of the std::string class in C++. It
returns a pointer to an array that contains a null-terminated sequence of
characters (i.e., a C-string) representing the current value of the
std::string object.

In the context of your function readFileIntoString, c_str() is called on the
path variable, which is of type std::string, to convert it to a C-style
string. Here's why it's used:

In C++98, the constructor of std::ifstream (input file stream) does not accept
a std::string directly. Instead, it expects a const char* type, which is the
traditional C-style string. The c_str() function is used to convert the
std::string path to a C-style string, so it can be passed to the std::ifstream
constructor.
 */

// Note 2
// Check if the file has been successfully opened
// is_open() returns true if the file is open, false otherwise

/* Note 3

std::ostringstream buffer;
buffer << input_file.rdbuf();

The same like (but this is more efficient)
std::ostringstream buffer(input_file.rdbuf());

Or the same like
std::ostringstream buffer << input_file.rdbuf();

std::string buffer;
std::string line;
while (std::getline(input_file, line)) {
	buffer += line + '\n'; // Repeatedly append to the string
}

*/
