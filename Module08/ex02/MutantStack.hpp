/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:39:30 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/10 17:58:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <list>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>( void );
		MutantStack<T>( MutantStack const & src );
		MutantStack&	operator=( MutantStack const & rhs );
		~MutantStack( void );
		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin( void );
		iterator	end( void );
};

#include "MutantStack.tpp"
