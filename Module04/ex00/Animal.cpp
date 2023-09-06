/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:11 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:06:13 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type ("generic animal") {
		std::cout << "default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type); 
}