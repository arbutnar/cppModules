/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:48:50 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/24 18:16:02 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

	int main() {

	try {
		Span sp = Span(10000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.getSize() << std::endl;
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addMore(100);
		std::cout << sp.getSize() << std::endl;


	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}