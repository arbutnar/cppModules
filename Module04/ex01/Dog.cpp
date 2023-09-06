/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:44 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:21:16 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal() {
	this->type = "dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
	: Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog decostructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "\033[1;32mWoof woof\033[0m" << std::endl;
}
