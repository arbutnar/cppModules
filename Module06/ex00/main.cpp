/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:04:03 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/07 17:00:07 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int	main( int argc, char *argv[]) {

	if (argc != 2)
		return 1;
	Scalar obj ( argv[1] );
	std::cout << obj << std::endl;
    
	return 0;
}