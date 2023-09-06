#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &src);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys(void);
};