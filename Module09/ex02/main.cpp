/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:53:42 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/15 19:12:07 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int argc, char **argv ) {

    try {
        if (argc < 3)
            throw std::invalid_argument("Invalid Argument");

        PmergeMe p(argv);
	    std::cout << "Before: ";
        p.display();
        std::cout << "After: ";
        p.display();
        
    } catch( const std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
