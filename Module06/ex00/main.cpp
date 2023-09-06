/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:15:37 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/27 18:15:37 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Bad arguments\n";
		return (1);
	}
	try {
		Scalar sc(argv[1]);
		sc.convert(sc.getLiteral());
	} catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}