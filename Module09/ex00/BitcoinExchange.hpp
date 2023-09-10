/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:22:38 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/10 17:50:44 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>

class BitcoinExchange {
	
	private:
		std::map<std::string, double> _map;

	public:
		class	CannotOpenFile;
		class	DataError;
		class	DataInvalidValue;
	
		BitcoinExchange( char* filename );
		BitcoinExchange( const BitcoinExchange &src );
		BitcoinExchange& operator=( const BitcoinExchange &src );
		~BitcoinExchange( void );
		
		int		checkPair( std::string key, std::string value );
		void	exchange( std::string filename );
	
};
