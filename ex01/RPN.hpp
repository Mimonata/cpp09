/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:22:47 by spitul            #+#    #+#             */
/*   Updated: 2026/01/01 18:54:44 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
	private:
		std::stack<double>	_nb;
		void	add(double a, double b);
		void	subtract(double a, double b);
		void	multiply(double a, double b);
		void	divide(double a, double b);
			
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN &rh);
		RPN	&operator=(const RPN &rh);
		~RPN();

		void	executeOp(void (RPN::*f)(double, double));
		double 	getResult();

		class invalidInputException : public std::runtime_error
		{
			public:
				explicit invalidInputException (const std::string &msg);
		};

		class zeroDivisionException : public std::runtime_error
		{
			public:
				explicit zeroDivisionException (const std::string &msg);
		};

		class emptyStackException : public std::runtime_error
		{
			public:
				explicit emptyStackException (const std::string &msg);
		};
};

#endif
