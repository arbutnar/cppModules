#include "HumanB.hpp"

HumanB::HumanB(void)
	: name ("None"), weapon (NULL) {
}

HumanB::HumanB(std::string name)
	: name (name), weapon (NULL) {
}

HumanB::~HumanB(void) {
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack(void) {
	if (!this->weapon)
		std::cout << this->name << " cannot attack. Better equip!" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}