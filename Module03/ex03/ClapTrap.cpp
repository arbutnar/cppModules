#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
	: name ("unnamed"), hp (10), ep(10), dp(0) {
		std::cout << "\033[1;33mdefault ClapTrap constructor\033[0m" << std::endl;
}

ClapTrap::ClapTrap( std::string name )
	: name (name), hp (10), ep(10), dp(0) {
		std::cout << "\033[1;33mClapTrap " << this->name << " constructed\033[0m" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "\033[1;33mClapTrap " << this->name << " deconstructed\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->dp = src.dp;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name << " dead" << std::endl;
		return ;
	}
	if (this->ep < 1) {
		std::cout << "ClapTrap " << this->name << "cannot attack; insufficient energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->dp << " points of damage!" << std::endl;
	this->ep -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage!" << std::endl;
	this->hp -= amount;
	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name << " dead" << std::endl;
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name << " dead" << std::endl;
		return ;
	}
	if (this->ep > 0) {
		std::cout << "ClapTrap " << this->name << " restored " << amount << " health!" << std::endl;
		this->hp += amount;
	} else
		std::cout << "ClapTrap " << this->name << "cannot restore health; insufficient energy!" << std::endl;
}

void	ClapTrap::setDp(unsigned int amount) {
	this->dp = amount;
}

int	ClapTrap::getDp( void ) {
	return (this->dp);
}

int ClapTrap::getHp( void ) {
	return (this->hp);
}

