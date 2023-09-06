#pragma once
#include <iostream>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie( void );
		~Zombie( void );
		void	announce( void );
		void	setName( std::string n );
		Zombie*	newZombie( std:: string name );
		void	randomChump( std::string name );
};