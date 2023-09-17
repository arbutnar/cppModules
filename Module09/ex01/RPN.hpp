/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:33:05 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/17 15:40:07 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <stack>
# include <queue>

class RPN {

    private:
        std::stack<int> _executorStack;

    public:
        RPN( void );
        RPN( char *str );
        RPN( const RPN &src );
        RPN& operator=( const RPN &src );
        ~RPN();

        int	    solve( std::string exp );
        void    performOperation( std::stack<int> &stack, std::string c );

        class errorException : public std::exception {
            virtual const char* what() const throw() { return("Error occured in operation"); };
        };
};
