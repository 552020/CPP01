#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {

  // TODO: read this:
  // https://chat.openai.com/share/28d10123-e5fc-402a-bef9-e8ddc801cff1 above
  // all why we need to
  //  initialize the weapon in the constructor of HumanA as reference and not as
  //  pointer and in the initialization list
  // first block scope
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  // second block scope
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }

  return (0);
}