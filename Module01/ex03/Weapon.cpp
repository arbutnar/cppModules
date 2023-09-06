#include "Weapon.hpp"

Weapon::Weapon(void) {
}

Weapon::Weapon(std::string type)
	: type (type) {
}

Weapon::~Weapon(void) {
}

void	Weapon::setType(std::string newtype) {
	this->type = newtype;
}

std::string&		Weapon::getType(void) {
	return (this->type);
}