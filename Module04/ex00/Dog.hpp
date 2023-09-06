/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:39 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:06:40 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal {

	public:
	    Dog();
		Dog(const Dog &src);
	    virtual ~Dog();

		Dog &operator=(const Dog &src);

		void makeSound() const;
};
