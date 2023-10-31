#include <string>

class Harl {
public:
  Harl();
  ~Harl();
  void complain(std::string level);
  void complain_if_else(std::string level);

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
};