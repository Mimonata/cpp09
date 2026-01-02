/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:50 by spitul            #+#    #+#             */
/*   Updated: 2026/01/02 23:47:03 by spitul           ###   ########.fr       */
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
		}
		if (!input.eof())
				throw std::runtime_error("Invalid input");
	}
	size = v.size();
}

PmergeMe::PmergeMe(const PmergeMe &rh) : v(rh.v), d(rh.d), size(rh.size)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe &rh)
{
	if (this != &rh)
	{
		v = rh.v;
		d = rh.d;
		size = rh.size;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::PmergeMeSort()
{
	std::vector<pair>	pairs;
	pair	p;
	int		last = -1;
	
	if (size % 2 == 1)
		last = v[size - 1];
	pairs.reserve(size / 2 + 1);
	for (int i = 0; i < size; i += 2)
	{
		if (i + 1 < size)
		{
			if (v[i] > v[i + 1])
			{
				p.large = v[i];
				p.small = v[i + 1];
			}
			else
			{
				p.large = v[i + 1];
				p.small = v[i];
			}
			pairs.push_back(p);
		}
	}
}

void	PmergeMe::sortVector()
{}

void	PmergeMe::sortDeque()
{}
