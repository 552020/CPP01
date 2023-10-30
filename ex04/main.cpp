#include <fstream>
#include <iostream>
#include <sstream> // ostringstream
#include <string>  // getline, string

std::string readFileIntoString(const std::string &path) {
  // Note 1
  std::ifstream input_file(path.c_str());
  // Note 2
  if (!input_file.is_open()) {
    std::cerr << "Could not open the file - '" << path << "'" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::ostringstream buffer;
  buffer << input_file.rdbuf();
  input_file.close();
  return (buffer.str());
}

void writeStringIntoFile(const std::string &path, const std::string &content) {
  std::ofstream output_file(path.c_str());
  if (!output_file.is_open()) {
    std::cerr << "Could not open the file - '" << path << "'" << std::endl;
    exit(EXIT_FAILURE);
  }
  output_file << content;
  output_file.close();
}

std::string replaceOccurences(std::string file_content,
                              const std::string toReplace,
                              const std::string replacer) {
  size_t pos = 0;
  while ((pos = file_content.find(toReplace, pos)) != std::string::npos) {
    std::string strBefore = file_content.substr(0, pos);
    std::string strAfter = file_content.substr(pos + toReplace.length());
    file_content = strBefore + replacer + strAfter;
    // The serarch should continue after the replaced string
    pos += replacer.length();
  }
  return (file_content);
}

int main(int argc, char **argv) {

  std::ifstream infile;
  std::string s1;
  std::string s2;
  std::string content;
  std::string new_content;

  if (argc != 4) {
    std::cout << "argc = " << argc << std::endl;
    std::cerr << "Usage: " << argv[0]
              << " <file_path> <string_to_replace> <replacement_string>"
              << std::endl;
    return 1;
  }
  std::string file_path = argv[1];
  s1 = argv[2];
  s2 = argv[3];
  content = readFileIntoString(file_path);
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
