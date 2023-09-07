/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:59:28 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/07 17:16:46 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#include <iostream>
#include <cstdlib>
#include <iomanip>

class Scalar {
	friend std::ostream	&operator<<( std::ostream &os, const Scalar &rhs );

	private:
		std::string	literal;
		int	type;
		int	status;
		enum	Type { charType, intType, floatType, doubleType, invalidType };
		enum	Status { valid, invalid, negInf, posInf, nan, nanf };
		char	charValue;
		int	intValue;
		float	floatValue;
		double	doubleValue;
		struct	impossibleException : public std::exception {
			const char	*what( void ) const	throw( );
		};
		struct negInfException : public std::exception {
			const char	*what( void ) const	throw( );
		};
		struct posInfException : public std::exception {
			const char	*what( void ) const	throw( );
		};
		struct nanException : public std::exception {
			const char	*what( void ) const	throw( );
		};
		struct nanfException : public std::exception {
			const char	*what( void ) const	throw( );
		};

	public:
		Scalar( void );
		Scalar( char *literal );
		Scalar( const Scalar &src );
		~Scalar( void );
		Scalar	&operator=( const Scalar &rhs );

		std::string	getLiteral( void ) const;
		char		getChar( void ) const;
		int			getInt( void ) const;
		float		getFloat( void ) const;
		double		getDouble( void ) const;
		int			detectStatus( void ) const;
		int			detectType( void ) const;
		void		fromChar( void );
		void		fromInt( void );
		void		fromFloat( void );
		void		fromDouble( void );
};