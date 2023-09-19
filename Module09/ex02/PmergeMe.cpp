/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:12:21 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/19 16:13:01 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
	: _vecTime (0.0), _deqTime (0.0) {
	throw std::invalid_argument("Error");
}

PmergeMe::PmergeMe( char **args )
	: _vecTime (0.0), _deqTime (0.0) {
	for (unsigned int i = 1; args[i] != NULL; i++)
	{
		std::string line = static_cast<std::string>(args[i]);
		if (line.find_first_not_of("0123456789+") != std::string::npos)
			throw std::invalid_argument("Error");
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
	double v_startTime = std::clock();
	mergeInsert( _vec, 0, _vec.size() - 1);
	double v_endTime = std::clock();
	setVecTime(1000.0 * ((v_endTime - v_startTime) / CLOCKS_PER_SEC));

	double d_startTime = std::clock();
	mergeInsert( _deq, 0, _deq.size() - 1);
	double d_endTime = std::clock();
	setDeqTime(1000.0 * ((d_endTime - d_startTime) / CLOCKS_PER_SEC));
}

template <typename T>
void	PmergeMe::mergeInsert( T& container, int begin, int end ) {
	if (end - begin > 5)
	{
		int mid = (begin + end) / 2;
		mergeInsert(container, begin, mid);
		mergeInsert(container, mid + 1, end);
		merge(container, begin, mid, end);
	}
	else
		insertSort( container, begin, end );
}

template <typename T>
void	PmergeMe::insertSort( T& container, int begin, int end ) {
	for (int i = begin; i < end; i++)
	{
		int tempVal = container[i + 1];
		int j = i + 1;
		while (j > begin && container[j - 1] > tempVal) {
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
			i++;
		} else {
			temp[k] = container[j];
			j++;
		}
		k++;
	}
	for (; i <= mid; i++, k++)
		temp[k] = container[i];
	for (; j <= end; j++, k++)
		temp[k] = container[j];
	for (i = begin; i < k; i++)
		container[i] = temp[i];
}

void	PmergeMe::display( void ) {
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::setVecTime( double time ) {
	this->_vecTime = time;
}

void	PmergeMe::setDeqTime( double time ) {
	this->_deqTime = time;
}

double	PmergeMe::getVecTime( void ) {
	return (this->_vecTime);
}

double	PmergeMe::getDeqTime( void ) {
	return (this->_deqTime);
}
