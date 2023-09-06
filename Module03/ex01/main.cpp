#include "ScavTrap.hpp"

int main() {

	ScavTrap	c1("Scavvy");
	ScavTrap	c2("Trappy");
	ScavTrap	c3 = c1;

	c1.attack("Balbio");
	c2.attack("Scavvy");
	c3.attack("Trappy");
	c1.guardGate();
	c2.guardGate();
	c3.guardGate();
}