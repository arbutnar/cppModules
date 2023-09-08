/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:54:37 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/08 18:54:37 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {

	Array<int> ar1(5);

	ar1.displayElements();
	std::cout << "size Array1 = " << ar1.getSize() << std::endl;
	ar1.setElements(55);
	Array<int> ar2;
	ar2 = ar1;
	try {
		ar1[0] = 0;
		ar2[0] = 234;
		ar1.displayElements();
		ar2.displayElements();
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
