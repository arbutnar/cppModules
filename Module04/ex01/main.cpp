/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:53 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:42:42 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N 4

int main() {

	Animal *a[N];

	for (int i = 0; i < N; i++) {
		if (i < 5)
			a[i] = new Dog();
		else
			a[i] = new Cat();
		a[i]->makeSound();
	}

	std::cout << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "\033[1;31mDeleting animal " << i + 1 << "\033[0m" << std::endl;
		delete a[i];
	}

	Cat cat;
	Cat cat1(cat);

	cat = cat1;
	
	return 0;
}