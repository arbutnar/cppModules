/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:05 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:07:07 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
	    WrongCat();
		WrongCat(const WrongCat &src);
	    virtual ~WrongCat();

		WrongCat &operator=(const WrongCat &src);
	
	    virtual void makeSound() const;
};
