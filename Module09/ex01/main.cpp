/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:59:31 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/17 14:06:03 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char **argv ) {

    try {
        if (argc != 2)
            throw std::invalid_argument("Error");
        RPN rpn(argv[1]);
    } catch( std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
