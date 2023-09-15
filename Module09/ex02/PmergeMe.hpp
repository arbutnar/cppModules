/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:30:35 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/15 19:19:28 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdlib.h>
# include <cstdlib>
# include <list>
# include <deque>

class PmergeMe {

	private:
		std::list<int>		_list;
		std::deque<int>		_deque;
		double				_listTime;
		double				_dequeTime;
		int					_size;

	public:
		PmergeMe( void );
		PmergeMe( char** args );
		PmergeMe( const PmergeMe &src );
		PmergeMe& operator=( const PmergeMe &src );
		~PmergeMe();

		std::list<int>	getList( void);
		int 			getSize( void );

		void			setListTime( double time );
		void			setDequeTime( double time );

		void	display( void );
		void	sortContainer( void );
		void	merge( void );
		
};
