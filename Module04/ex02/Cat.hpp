/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:22 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 18:17:51 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"

class Cat: public AAnimal {

	public:
		Cat();
		Cat(const Cat &src);
		~Cat( void );

		Cat &operator=(const Cat &src);
		
		void makeSound() const;
};