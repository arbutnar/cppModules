/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:23:49 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/15 18:28:27 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <sstream>
# include <stdlib.h>
# include <cstdlib>
# include <vector>
# include <stack>

class RPN {

	private:
		std::stack<int> _temp;

	public:
		RPN( void );
		RPN( const char* exp );
		~RPN();
		RPN( const RPN &src );
		RPN& operator=( const RPN &src );

		int	solve( std::string exp );
		void perform_operation( std::stack<int> &s, char c );

		class errorException : public std::exception {
			public:
				virtual const char* what() const throw() { return("Error"); }
		};
};
