/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:12:21 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/17 20:12:14 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
	: _vecTime (0.0), _deqTime (0.0) {
	throw std::invalid_argument("Error");
}

PmergeMe::PmergeMe( char **args )
	: _vecTime (0.0), _deqTime (0.0) {
	for (unsigned int i = 1; args[i]; i++)
	{
		std::string line = static_cast<std::string>(args[i]);
		if (line.find_first_not_of("0123456789-") != std::string::npos)
			throw std::invalid_argument("Invalid Argument");
		else
		{
			_vec.push_back( std::atoi(line.c_str()) );
			_deq.push_back( std::atoi(line.c_str()) );
		}
	}
}

PmergeMe::PmergeMe( const PmergeMe &src )
	: _vec (src._vec), _deq (src._deq), _vecTime (src._vecTime), _deqTime (src._deqTime)  {
}

PmergeMe& PmergeMe::operator=( const PmergeMe &src ) {
	if (this != &src)
	{
		_vec = src._vec;
		_deq = src._deq;
		_vecTime = src._vecTime;
		_deqTime = src._deqTime;
	}
	return (*this);
}

PmergeMe:: ~PmergeMe() {
	_vec.clear();
	_deq.clear();
}

void	PmergeMe::sortContainers( void ) {
	std::clock_t v_startTime = std::clock();
	mergeInsert( _vec, 0, _vec.size() - 1);
	std::cout << "SIZE: "<< _vec.size() << std::endl;
	std::clock_t v_endTime = std::clock();
	setVecTime(1000.0 * (v_endTime - v_startTime) / CLOCKS_PER_SEC);

	std::clock_t d_startTime = std::clock();
	mergeInsert( _deq, 0, _deq.size() - 1);
	std::clock_t d_endTime = std::clock();
	setDeqTime(1000.0 * (d_endTime - d_startTime) / CLOCKS_PER_SEC);
}

template <typename T>
void	PmergeMe::mergeInsert( T& container, int begin, int end ) {
	if (end - begin > 5)
	{
		int mid = (end - begin) / 2;
		mergeInsert(container, begin, mid);
		mergeInsert(container, mid + 1, end);
		merge(container, begin, mid, end);
	}
	else
		insertSort( container );
}

template <typename T>
void	PmergeMe::insertSort( T& container ) {
	for (unsigned int i = 0; i < container.size(); i++)
	{
		int tempVal = container[i + 1];
		int j = i + 1;
		while (j > 0 && container[j - 1] > tempVal) {
			container[j] = container[j - 1];
			j--;
		}
		container[j] = tempVal;
	}
}

template <typename T>
void	PmergeMe::merge( T& container, int begin, int mid, int end ) {
	int i = begin;
	int k = begin;
	int j = mid + 1;
	int temp[container.size()];
	while (i <= mid && j <= end)
	{
		if (container[i] < container[j]) {
			temp[k] = container[i];
			k++;
			i++;
		} else {
			temp[k] = container[j];
			k++;
			j++;
		}
	}
	for (; i <= mid; i++ && k++)
		temp[k] = container[i];
	for (; j <= end; j++ && k++)
		temp[k] = container[j];
	for (i = begin; i < k; i++)
		container[i] = temp[i];
}

void	PmergeMe::display( void ) {
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::setVecTime( double t ) {
	this->_vecTime = t;
}

void	PmergeMe::setDeqTime( double t ) {
	this->_deqTime = t;
}

double	PmergeMe::getVecTime( void ) {
	return (this->_vecTime);
}

double	PmergeMe::getDeqTime( void ) {
	return (this->_deqTime);
}
