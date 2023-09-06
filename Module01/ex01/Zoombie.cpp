#include "Zombie.hpp"

Zombie::Zombie() {

}


Zombie::~Zombie() {
	std::cout << "Bimbo destroyed" << std::endl;
}

void	Zombie::setName(std::string n) {
	name = n;
}

void	Zombie::announce(void) {
	std::cout << name << ":: BraiiiiiiinnnzzzZ.." << std::endl;
}