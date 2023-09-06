/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:10:36 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:10:37 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice") {
}

Ice::Ice(const AMateria &src) {
	*this = src;
}

Ice	&Ice::operator=(const AMateria &src) {
	if (this == &src)
		return (*this);
	this->type = src.getType();
	return (*this);
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
	AMateria *ice = new Ice();
	return (ice);
}

void Ice::use(ICharacter& target) {
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}