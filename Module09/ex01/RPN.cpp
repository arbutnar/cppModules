/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:18:09 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/15 18:28:22 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {
	throw std::invalid_argument("Invalid Argument");
}

RPN::RPN( const char* exp ) {
	std::string str = static_cast<std::string>(exp);
	if (solve(str))
		throw RPN::errorException();
}

RPN::~RPN() {

}

RPN::RPN( const RPN &src ) {
	*this = src;
}

RPN &RPN::operator=( const RPN &src ) {
	(void)src;
	return *this;
}

void RPN::perform_operation( std::stack<int> &_temp, char c )
{
	char signs[4] = {'+', '-', '*', '/'};
	int first;
	int sec;
	int res;
	first = _temp.top();
	_temp.pop();
	sec = _temp.top();
	_temp.pop();
	unsigned int i;
	for (i = 0; i < 4; i++)
		if (c == signs[i])
			break ;
	switch(i) {
		case 0:
			res = sec + first;
			break ;
		case 1:
			res = sec - first;
			break ;
		case 2:
			res = sec * first;
			break ;
		case 3:
			res = sec / first;
			break ;
		default:
			return ;
	}
	_temp.push(res);
	if (_temp.size() < 1)
		throw RPN::errorException();
}

int RPN::solve( std::string exp ) {
	if (exp.find_first_not_of("0123456789+-/* ") != std::string::npos)
		return 1;
	
	std::vector<std::string> vec;
	std::stringstream ss(exp);
	std::string str;
	while (std::getline(ss, str, ' '))
		vec.push_back(str);
	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec[i].find_first_not_of("0123456789") != std::string::npos) {
			if (vec[i].size() != 1)
				throw std::invalid_argument("Error");
			else
				perform_operation(_temp, vec[i][0]);
		}
		else
			_temp.push(atoi(vec[i].c_str()));
	}
	while (!_temp.empty()) {
		std::cout << _temp.top() << std::endl;
		_temp.pop();
	}
	return 0;
}
