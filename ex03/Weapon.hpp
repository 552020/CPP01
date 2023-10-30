#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
  Weapon(std::string type);
  ~Weapon();
  // std::string const &getType() const;
  std::string getType() const;
  void setType(std::string type);

private:
  std::string _type;
};

#endif