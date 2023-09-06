/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:18 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:43:37 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: AAnimal() {
	this->type = "cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
	: AAnimal(src) {
		std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat copy assignment constructor" << std::endl;
	if (this != &src)
		AAnimal::operator=(src);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat decostructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}
