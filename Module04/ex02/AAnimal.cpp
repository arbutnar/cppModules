/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:01 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:44:15 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
	: type (" ") {
		this->brain = new Brain();
		std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
	: type (src.type) {
		std::cout << "AAnimal copy constructor" << std::endl;
		this->brain = new Brain(*(src.brain));
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
	std::cout << "AAnimal copy assignment constructor" << std::endl;
	if (this == &src)
		return (*this);
	if (this->brain != NULL)
		delete (this->brain);
	this->brain = new Brain(*(src.brain));
	return (*this);
}

AAnimal::~AAnimal() {
	delete (this->brain);
	std::cout << "AAnimal decostructor called" << std::endl;
}

std::string AAnimal::getType() {
	return (this->type);
}