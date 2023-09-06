/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 19:23:54 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {

	protected:
	    std::string type;
		Brain *brain;

	public:
	    Animal();
		Animal(const Animal &src);
	    virtual ~Animal();

		Animal &operator=(const Animal &src);

	    virtual void makeSound() const;
		std::string getType() const;
};