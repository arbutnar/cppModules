/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:09:11 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:09:12 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	: type (" ") {
}

AMateria::AMateria(std::string const &type)
	: type (type) {
}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}
		
AMateria &AMateria::operator=(const AMateria &src) {
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

AMateria::~AMateria() {
};

std::string const &AMateria::getType() const {
	return (this->type);
}
