/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:35 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 18:18:42 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"

class Dog: public AAnimal {
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
	
		Dog &operator=(const Dog &src);
	
		void makeSound() const ;
};