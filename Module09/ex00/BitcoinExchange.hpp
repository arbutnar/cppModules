/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:22:38 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/11 16:37:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>
# include <bits/stdc++.h>

class BitcoinExchange {
	
	private:
		std::map<std::string, double> _exchangeMap;

	public:

		typedef	std::map<std::string, double>::iterator iterator;
		
		class	CannotOpenFile;
		class	DataError;
		class	DataInvalidValue;
		class	InputError;
	
		BitcoinExchange( void );
		BitcoinExchange( const char *filename );
		BitcoinExchange( const BitcoinExchange &src );
		BitcoinExchange& operator=( const BitcoinExchange &src );
		~BitcoinExchange( void );
		
		int		checkPair( std::string const &date, std::string const &value );
		void	exchange( const char *filename );
	
};
