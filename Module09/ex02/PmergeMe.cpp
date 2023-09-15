/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:33:58 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/15 19:21:55 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
	: _listTime (0.0), _dequeTime (0.0), _size (0) {

		throw std::invalid_argument("Invalid Argument");
}

PmergeMe::PmergeMe( char** args )
	:  _listTime (0.0), _dequeTime (0.0), _size (0) {

	for (unsigned i = 1; args[i] != '\0'; i++)
	{
		std::string str = static_cast<std::string>(args[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Invalid Argument");
		else
		{
			_list.push_back(atoi( str.c_str() ));
			_deque.push_back(atoi( str.c_str() ));
			_size += 1;
		}
	}
}

PmergeMe::PmergeMe( const PmergeMe &src )
	: _list ( src._list ) {
}

PmergeMe&	PmergeMe::operator=( const PmergeMe &src ) {
	if (this != &src)
		this->_list = src._list;
	return (*this);
}

PmergeMe::~PmergeMe() {
	_list.clear();
}

int 	PmergeMe::getSize() {
	return (this->_size);
}

void	PmergeMe::display() {
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::sortContainer( void ) {

}
// void	PmergeMe::merge()
