/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:49 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 17:22:43 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog: public Animal {

	public:
		Dog();
		Dog(const Dog &src);
		~Dog( void );

		Dog &operator=(const Dog &src);

		void makeSound() const;
};