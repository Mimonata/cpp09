/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:22:37 by spitul            #+#    #+#             */
/*   Updated: 2026/01/01 19:37:13 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN()
{}

RPN::RPN(std::string input)
{
	std::stringstream	stream(input);
	std::string			token;
	int					num;
	
	while (std::getline(stream, token, ' '))
	{
		if (token.empty())
			continue;
		if ((token.size() == 1 && isdigit(token[0])) || (token.size() == 2 && token[0] == '-'))
		{
			std::stringstream(token) >> num;
			_nb.push(num);
		}
		else if (token[0] == '+')
			executeOp(&RPN::add);
		else if (token[0] == '-')
			executeOp(&RPN::subtract);
		else if (token[0] == '*')
			executeOp(&RPN::multiply);
		else if (token[0] == '/')
			executeOp(&RPN::divide);
		else
			throw RPN::invalidInputException("Invalid token " + token);		
	}
}

RPN::RPN(const RPN &rh)
{
	*this = rh;
}

RPN& RPN::operator=(const RPN &rh)
{
	if (this != &rh)
		_nb = rh._nb;
	return *this;
}

RPN::~RPN()
{}

RPN::invalidInputException::invalidInputException(const std::string &msg) : std::runtime_error(msg)
{}

RPN::zeroDivisionException::zeroDivisionException(const std::string &msg) : std::runtime_error(msg)
{}

RPN::emptyStackException::emptyStackException(const std::string &msg) : std::runtime_error(msg)
{}

void	RPN::executeOp(void (RPN::*f)(double, double))
{
	double	a;
	double	b;
	
	if (_nb.size() < 2)
		throw RPN::invalidInputException("Not enough arguments");
	a = _nb.top();
	_nb.pop();
	b= _nb.top();
	_nb.pop();
	(this->*f)(a, b);
}

void	RPN::add(double a, double b)
{
	_nb.push(a + b);
}

void	RPN::subtract(double a, double b)
{
	_nb.push(b - a);
}

void	RPN::multiply(double a, double b)
{
	_nb.push(a * b);
}

void	RPN::divide(double a, double b)
{
	if (a != 0)
		_nb.push(b / a);
	else
		throw RPN::zeroDivisionException("Division by zero intended");
}

double RPN::getResult()
{
	if (_nb.size() > 1)
		throw RPN::invalidInputException("Invalid input");
	else if (_nb.empty())
		throw RPN::emptyStackException("Stack empty");
	return _nb.top();
}
