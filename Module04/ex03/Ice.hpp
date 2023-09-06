/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:10:32 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:10:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {

	public:
		Ice();
		~Ice();
		Ice(const AMateria &src);
		Ice &operator=(const AMateria &src);

		AMateria* clone() const;
		void use(ICharacter& target);
};
