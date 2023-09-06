/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:20 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:06:22 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Animal {

	protected:
	    std::string type;

	public:
	    Animal();
		Animal(const Animal &src);
	    virtual ~Animal();

		Animal &operator=(const Animal &src);

	    virtual void makeSound() const;
		std::string getType() const;
};
