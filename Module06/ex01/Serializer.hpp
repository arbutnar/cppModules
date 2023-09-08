/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:23:06 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/08 16:28:53 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"

class Serializer {

	public:
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );
};