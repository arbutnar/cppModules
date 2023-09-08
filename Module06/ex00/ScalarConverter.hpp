/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:59:28 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/08 17:23:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

# include <iostream>
# include <cstdlib>
# include <iomanip>

enum	Type { CHAR, INT, FLOAT, DOUBLE, NOTYPE };
enum	Pseudo { NEGINF, POSINF, NAN, NANF, NOPSEUDO };

class ScalarConverter {

	private:
		static std::string	_literal;
		static int			_type;
		static Pseudo		_pseudo;
		static char			_charValue;
		static int			_intValue;
		static float		_floatValue;
		static double		_doubleValue;

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
		static std::string	getLiteral( void );
		static char			getChar( void );
		static int			getInt( void );
		static float		getFloat( void );
		static double		getDouble( void );
		static void			detectPseudo( void );
		static int			detectType( void );
		static void			fromChar( void );
		static void			fromInt( void );
		static void			fromFloat( void );
		static void			fromDouble( void );

		static void			convert( char *_literal );
		static void			display( );
};
