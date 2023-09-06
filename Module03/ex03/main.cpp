#include "DiamondTrap.hpp"

int main() {

	DiamondTrap trappp("Balbio");
	DiamondTrap diam = trappp;

	diam.attack("Lucia");
	trappp.whoAmI();
}