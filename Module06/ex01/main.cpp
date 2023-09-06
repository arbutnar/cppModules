/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:22:58 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/05 17:57:22 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

	Data data;
	Data *ptr = &data;
	Serializer s;

	std::cout << "age: " << ptr->age << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << "surname: " << ptr->surname << std::endl;

	uintptr_t i;
	i = s.serialize(ptr);
	ptr = s.deserialize(i);

	std::cout << "age: " << ptr->age << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << "surname: " << ptr->surname << std::endl;
	
	return 0;
}