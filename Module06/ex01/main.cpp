/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:22:58 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/08 17:27:44 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

	Data data;
	Data *ptr = &data;
	Serializer s;

	ptr->age = 56;
	ptr->name = "Balbio";
	ptr->surname = "Babbio";

	uintptr_t	i = Serializer::serialize(ptr);
	ptr = Serializer::deserialize(i);

	std::cout << "age: " << ptr->age << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << "surname: " << ptr->surname << std::endl;

	return 0;
}