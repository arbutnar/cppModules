/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:57:48 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/05 15:16:46 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <float.h>

#ifndef NAN
#define NAN (0.0/0.0)
#endif

enum Types { charType, intType, floatType, doubleType, invalidType };
enum Status { inf, posInf, negInf, nan, nanf, null };

class Scalar {

	private:
		std::string literal;
		Types type;
		Status state;

	public:
		Scalar(char *str);
		Scalar(const Scalar &src);
		Scalar &operator=(const Scalar &src);
		~Scalar();

		std::string getLiteral();
		char	*toChar(int i);
		int     detectStatus(std::string literal);
		int     detectType(std::string literal);
		void    convert(std::string literal);
};