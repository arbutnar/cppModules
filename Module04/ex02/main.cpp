/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:43 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:45:10 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {

	//const AAnimal* j = new AAnimal();	//Compiler Error due to trying to instantiate abstract obj
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	j->makeSound();
	i->makeSound();
	
	delete j;
	delete i;

	return 0;
}