#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

std::string readFileIntoString(const std::string &path)
{
	std::ifstream input_file(path.c_str());
	if (!input_file.is_open())
	{
		std::cerr << "Could not open the file - '" << path << "'" << std::endl;
		std::exit(1);
	}
	std::ostringstream buffer;
	buffer << input_file.rdbuf();

	input_file.close();
	return (buffer.str());
}

void writeStringIntoFile(const std::string &path, const std::string &content)
{
	std::ofstream output_file(path.c_str());
	if (!output_file.is_open())
	{
		std::cerr << "Could not open the file - '" << path << "'" << std::endl;
		std::exit(1);
	}
	output_file << content;
	output_file.close();
}

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
		pos += replacerLength;
	}
	return (fileContent);
}

void checks(std::string &s1, std::string &s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error! The strings can't be empty" << std::endl;
		std::exit(1);
	}
	if (s1 == s2)
	{
		std::cerr << "Error! The strings are the same. Nothing to do!" << std::endl;
		std::exit(1);
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