/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:49:53 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/17 15:43:02 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {
	throw std::invalid_argument("Error");
}

RPN::RPN( char* arg ) {
	std::string exp = static_cast<std::string>(arg);
	if (!solve( exp ))
		throw std::invalid_argument("Error");
}

RPN::RPN( const RPN &src )
	: _executorStack (src._executorStack) {
}

RPN& RPN::operator=( const RPN &src ) {
	if (this != &src)
		this->_executorStack = src._executorStack;
	return (*this);
}

RPN::~RPN() {
}

void    RPN::performOperation( std::stack<int> &stack, std::string c ) {
	int i = 0;
	int res = 0;
	std::string	signs[4] = { "+", "-", "/", "*" };
	int n1 = stack.top();
	stack.pop();
	int n2 = stack.top();
	stack.pop();

	for (; i < 4; i++)
		if (signs[i] == c)
			break ;
	switch (i) {
		case 0:
			res = n2 + n1; break ;
		case 1:
			res = n2 - n1; break ;
		case 2:
			res = n2 / n1; break ;
		case 3:
			res = n2 * n1; break ;
		default:
			return ;
	}
	stack.push(res);
	if (stack.size() < 1)
		throw RPN::errorException();
}

int	RPN::solve( std::string exp ) {
	if (exp.find_first_not_of("0123456789+-/* ") != std::string::npos)
		return 0;

	std::stringstream ss(exp);
	std::string line;
	std::queue<std::string> queue;
	while (std::getline(ss, line, ' '))
		queue.push(line);
	while (!queue.empty())
	{
		if (queue.front().find_first_not_of("0123456789") != std::string::npos)
		{
			if (queue.front().size() != 1)
				return 0;
			else
				performOperation( _executorStack, queue.front() );
		} else
			_executorStack.push(std::atoi( queue.front().c_str()) );
		queue.pop();
	}

	while (!_executorStack.empty())
	{
		std::cout << _executorStack.top() << std::endl;
		_executorStack.pop();
	}

	return 1;
}
