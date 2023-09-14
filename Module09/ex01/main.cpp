/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:26:44 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/13 15:46:42 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char *argv[] ) {

    if (argc != 2)
        return 1;
    try {
        RPN r(argv[1]);
    } catch( std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
