#include "Zombie.hpp"

Zombie::Zombie()  {

}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string n ) {
	name = n;
}
