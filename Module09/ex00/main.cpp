/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:22:32 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/11 16:20:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char **argv ) {
    
    ( void )argc;
    try {
        BitcoinExchange btc("data.csv");
        btc.exchange(argv[1]);
    } catch( std::exception const &e ) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
