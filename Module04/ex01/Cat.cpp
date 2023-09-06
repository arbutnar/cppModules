/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:35 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:21:10 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal() {
	this->type = "cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
	: Animal(src) {
	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat decostructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "\033[1;32mMeow meow\033[0m" << std::endl;
}
