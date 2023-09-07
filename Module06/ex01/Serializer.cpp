/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:23:02 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/07 14:32:02 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {

}

Serializer::~Serializer( void ) {

}

uintptr_t Serializer::serialize( Data* ptr ) {
    std::cout << "Pointer serialied!\n";
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize( uintptr_t raw ) {
    std::cout << "Pointer deserialied!\n";
    return (reinterpret_cast<Data *>(raw));
}
