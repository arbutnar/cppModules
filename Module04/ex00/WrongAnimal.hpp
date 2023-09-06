/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:57 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:06:59 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include "Animal.hpp"

class WrongAnimal {

	protected:
	    std::string type;

	public:
	    WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
	    virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &src);

	    void makeSound() const;
		std::string getType() const;
};
