/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:10:56 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:10:58 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
			this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete (this->inventory[i]);
    }
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
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
void    MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL)
		return ;
    for (int idx = 0; idx < 4; idx++) {
    	if (inventory[idx] == NULL) {
			AMateria *tmp = m;
    		inventory[idx] = tmp->clone();
			delete (tmp);
			break ;
		}
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int idx = 0; idx < 4; idx++) {
    	if (inventory[idx] != NULL && inventory[idx]->getType() == type)
    		return (inventory[idx]->clone());
    }
	return (0);
}
