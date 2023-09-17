/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:30:53 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/17 20:05:10 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <vector>
# include <deque>

class PmergeMe {

	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		double				_vecTime;
		double				_deqTime;

	public:
		PmergeMe( void );
		PmergeMe( char **args );
		PmergeMe( const PmergeMe &src );
		PmergeMe& operator=( const PmergeMe &src );
		~PmergeMe();

		void	sortContainers( void );

		template <typename T>
		void	merge( T& container, int begin, int mid, int end );
		template <typename T>
		void	insertSort( T& container );
		template <typename T>
		void	mergeInsert( T& container, int begin, int end );

		void	setVecTime( double t );
		void	setDeqTime( double t );
		double	getVecTime( void );
		double	getDeqTime( void );
		void	display( void );
};
