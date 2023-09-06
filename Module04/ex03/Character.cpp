/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:09:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:09:24 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Node *Character::head = NULL;
Node *Character::tail = NULL;

Character::Character()
	: name (" ") {
		for (int i = 0; i < 4; i++)
			this->inventory[i] = NULL;
}

Character::Character(std::string name)
	: name (name) {
		for (int i = 0; i < 4; i++)
			this->inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete (this->inventory[i]);
	}
}
		
Character::Character(const Character &src) {
	*this = src;
}
		
Character &Character::operator=(const Character &src) {
	if (this == &src)
        return (*this);
    for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete (this->inventory[i]);
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i] != NULL) {
			this->inventory[i] = src.inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	for (int idx = 0; idx < 4; idx++) {
		if (inventory[idx] == NULL) {
			inventory[idx] = m;
			std::cout << this->getName() << " equipped with " << inventory[idx]->getType() << std::endl;
			break ;
		}
	}
}

void	Character::saveMaterias(AMateria *m) {
	if (head == NULL) {
		head = new Node();
		head->context = m;
		tail = head;
		return ;
	}
	tail->next = new Node();
	tail = tail->next;
	tail->context = m;
}

void Character::unequip(int idx) {
	if ((idx >= 0 && idx <= 3) && inventory[idx] != NULL) {
		std::cout << this->getName() << " unequipped " << inventory[idx]->getType() << " at slot " << idx << std::endl;
		saveMaterias(inventory[idx]);
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if ((idx >= 0 && idx <= 3) && inventory[idx] != NULL)
		inventory[idx]->use(target);
}

void Character::deleteList() {
	if (head == NULL)
		return ;
	Node *curr = head;
	Node *next = head->next;
	while (curr != NULL) {
		delete(curr->context);
		delete (curr);
		if (next == NULL)
			break ;
		curr = next;
		next = curr->next;
	}

}