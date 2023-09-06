#include "Contact.hpp"

class Phonebook {
	private:
		Contact	contacts[8];
		int		i;

	public:
		Phonebook();
		~Phonebook();
		void	add();
		void	contactList();
		void	searchInfo();
};