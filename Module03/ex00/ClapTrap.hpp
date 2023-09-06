#pragma once

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string	name;
		int	hp;
		int ep;
		int	dp;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setDp(unsigned int amount);
		int	getDp( void );
		int getHp( void );
};
