/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:49:02 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/10 17:54:49 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <iterator>

class Span {

	private:
		unsigned int	N;
		unsigned int	size;
		std::vector<int> v;

	public:
		class Overflow;
		class SpanNotFound;

		Span( unsigned int N );
		Span( const Span &src );
		~Span( void );

		Span &operator=( const Span &src );

		void	addNumber( int num );
		void	addMore( int num );
		int		shortestSpan( void );
		int		longestSpan( void );
		int		getSize( void );
};
