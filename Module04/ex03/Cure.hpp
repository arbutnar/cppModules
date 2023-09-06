/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:10:28 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:10:29 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {

	public:
		Cure();
		~Cure();
		Cure(const AMateria &src);
		Cure &operator=(const AMateria &src);

		AMateria* clone() const ;
		void use(ICharacter &target) ;
};
