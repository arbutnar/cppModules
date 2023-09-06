/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:06:30 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:06:31 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat: public Animal {

	public:
	    Cat();
		Cat(const Cat &src);
	    virtual ~Cat();

		Cat &operator=(const Cat &src);

	    void makeSound() const;
};
