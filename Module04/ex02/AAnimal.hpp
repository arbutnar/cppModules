/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:05 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 18:17:10 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal {

	protected:
		std::string type;
		Brain *brain;

	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		virtual ~AAnimal( void );

		AAnimal &operator=(const AAnimal &src);

		virtual void makeSound() const = 0;
		std::string getType();
};