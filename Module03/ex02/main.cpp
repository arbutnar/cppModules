#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	FragTrap	c1("Fraggy");
	FragTrap	c2("Trappy");
	FragTrap	c3 = c1;

	c1.attack("Trappy");
	c2.attack("Fraggy");
	c3.attack("Bimbo");
	c1.highFivesGuys();
	c2.highFivesGuys();
	c3.highFivesGuys();
}