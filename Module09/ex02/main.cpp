/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:29:56 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/17 20:07:55 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int argc, char **argv ) {

	try {
		if (argc < 3)
			throw std::invalid_argument("Invalid argument");

		PmergeMe	pme(argv);

		std::cout << "Before: ";
		pme.display();
		std::cout << "After: ";
		pme.sortContainers();
		pme.display();

		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << pme.getVecTime() << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " Elements with std::vector : " << pme.getDeqTime() << std::endl;
	} catch( std::exception &e ){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
