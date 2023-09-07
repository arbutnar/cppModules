/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:23:06 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/07 14:32:23 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"

class Serializer {

	public:
		Serializer( void );
		~Serializer( void );
		uintptr_t serialize( Data* ptr );
		Data* deserialize( uintptr_t raw );
};