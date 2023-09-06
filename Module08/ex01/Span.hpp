/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:49:02 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/24 18:13:48 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span {

	private:
		unsigned int	N;
		unsigned int	size;
		std::vector<int> v;

	public:
		class Overflow;
		class SpanNotFound;

		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);

		void	addNumber(int num);
		void	addMore(int num);
		int		shortestSpan();
		int		longestSpan();
		int		getSize();
};