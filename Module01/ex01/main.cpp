#include "Zombie.hpp"

int main() {
	int	N = 6;
	Zombie *horde = NULL;
	horde = zombieHorde(N, "Bimbi");

	for (int i = 0;i < N;i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}
