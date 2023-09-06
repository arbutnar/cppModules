#include "ClapTrap.hpp"

int main() {
	ClapTrap	Lothric("Lothric");
	ClapTrap	Mantissa("Mantissa");

	Lothric.attack("Mantissa");
	Mantissa.takeDamage(Lothric.getDp());
	Mantissa.beRepaired(Lothric.getDp());

	Mantissa.setDp(3);
	Mantissa.attack("Lothric");
	Lothric.takeDamage(Mantissa.getDp());
	Mantissa.setDp(8);
	Mantissa.attack("Lothric");
	Lothric.takeDamage(Mantissa.getDp());

	return 0;
}