/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:11 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:40:57 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type ("generic animal") {
		std::cout << "Animal default constructor called" << std::endl;
		this->brain = new Brain();
}

Animal::Animal(const Animal &src)
	: type (src.type) {
		this->brain = new Brain(*(src.brain));
		std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	delete (this->brain);
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
	if (this == &src)
		return (*this);
	this->type = src.type;
	if (this->brain != NULL)
	 	delete (this->brain);
	this->brain = new Brain(*(src.brain));
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type); 
}