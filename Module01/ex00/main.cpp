#include "Zombie.hpp"

int main() {
	Zombie zombie1;
	Zombie	*zombie2;

	zombie1.setName("Foo");
	zombie1.announce();
	zombie2 = zombie1.newZombie("Boo");
	zombie2->announce();
	zombie1.randomChump("Balbio");

	delete(zombie2);
	return (0);
}