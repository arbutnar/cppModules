/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:49:08 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/14 15:44:18 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class	Span::Overflow : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Span overflow"); }
};

class	Span::SpanNotFound : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Span not found - Error may be: zero or one nums stored "); }
};

Span::Span( unsigned int n )
	: N (n) {
		std::cout << "Span one arg constructor called" << std::endl;
}

Span::Span( const Span &src ) {
	std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span	&Span::operator=( const Span &src ) {
	std::cout << "Span copy assignment opeartor" << std::endl;
	if (this != &src)  {
		this->N = src.N;
		this->v = src.v;
	}
	return *this;
}

Span::~Span( void ) {
	std::cout << "Span deconstructor called" << std::endl;
	v.clear();
}

void	Span::addNumber( int num ) {
	if (size >= N)
		throw Span::Overflow();
	v.push_back(num);
	size++;
}

void	Span::addMore( int num ) {
	std::vector<int> tmp;

	srand(time(NULL));
	for (int i = 0; i < num; i++)
		tmp.push_back(rand()% 1000);
	if ((size + num) > N)
		throw Span::Overflow();
	size += num;
	v.insert(v.begin(), tmp.begin(), tmp.end());
}

int	Span::shortestSpan( void ) {
	if (size < 2)
		throw Span::SpanNotFound();
	sort(v.begin(), v.end());
	int ss = v[size - 1] - v[size - 2];

	for (unsigned int i = size - 2; i > 0; i--) {
		if (ss > v[i] - v[i - 1])
			ss = v[i] - v[i - 1];
	}
	return ss;
}

int	Span::longestSpan( void ) {
	if (size < 2)
		throw Span::SpanNotFound();
	sort(v.begin(), v.end());
	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());
	return (max - min);
}

int	Span::getSize( void ) {
	return size;
}