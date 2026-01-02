/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:50 by spitul            #+#    #+#             */
/*   Updated: 2026/01/02 22:57:45 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(int argc, char **argv)
{
	int	num;
	
	for (int i = 1; i < argc; i++)
	{
		std::stringstream	input(argv[i]);
		while (input >> num)
		{
			if (num >= 0)
			{
				v.push_back(num);
				d.push_back(num);
			}
			else
				throw std::runtime_error("Error: negative number enocuntered");
			if (!input.eof())
				throw std::runtime_error("Invalid input");
		}
	}
}

PmergeMe::PmergeMe(const PmergeMe &rh) : v(rh.v), d(rh.d)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe &rh)
{
	if (this != &rh)
	{
		v = rh.v;
		d = rh.d;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::PmergeMeSort()
{
	std::vector<pair>	pairs;
	
	for (int i = 0; i < v.size(); i++)
	{
		
	}
}

void	PmergeMe::sortVector()
{}

void	PmergeMe::sortDeque()
{}
