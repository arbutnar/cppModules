/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:26 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:43:17 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: AAnimal() {
	this->type = "dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
	: AAnimal(src) {
		std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog copy assignment constructor" << std::endl;
	if (this != &src)
		AAnimal::operator=(src);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog decostructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}
