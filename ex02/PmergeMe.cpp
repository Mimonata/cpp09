/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:50 by spitul            #+#    #+#             */
/*   Updated: 2026/01/03 23:27:50 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <stdexcept>

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
	
	if (len % 2 == 1)
		last = v[size - 1];
	pairs.reserve(size / 2 + 1);
	for (int i = 0; i < size; i += 2)
	{
		if (i + 1 < size)
		{
			p.large = std::max(v[i], v[i + 1]);
			p.small = std::min(v[i], v[i + 1]);
			pairs.push_back(p);
		}
	}
	std::cout << "Before: " << this;
	sortVector();
	sortDeque();
	std::cout << "After: " << this;
}

void	PmergeMe::sortVector(std::vector<int> &v, int size)
{
	std::vector<pair>	pairs;
	std::vector<int>	main;
	std::vector<int>	pend;
	pair	p;
	int		last = -1;
	
	if (size <= 1)
		return;
	if (size % 2 == 1)
		last = v[size - 1];
	for (int i = 0; i < size; i += 2)
	{
		if (i + 1 < size)
		{
			p.large = std::max(v[i], v[i + 1]);
			p.small = std::min(v[i], v[i + 1]);
			pairs.push_back(p);
		}
	}
	for (int i = 0; i < size / 2; i++)
	{
		main.push_back(pairs[i].large);
		pend.push_back(pairs[i].small);
	}
	sortVector(main, size / 2);
	insertPend(main, pairs, last);
}

void	PmergeMe::sortDeque()
{}

void	PmergeMe::insertPend(std::vector<int> &main, std::vector<pair> &pairs, int last)
{
	for (int i = 0; i < pairs.size(); i++)
	{
		
	}
}

std::ostream	&operator<<(std::ostream &os, PmergeMe &obj)
{
	std::vector<int>	v_copy;
	int					size_copy;

	v_copy = obj.getVector();
	size_copy = obj.getSize();
	for (int i = 0; i < size_copy; i++)
	{
		os << v_copy[i];
		if (i < size_copy - 1)
			os << ', ';
	}
	os << '\n';
	return os;
}

std::vector<int>	PmergeMe::getVector()
{
	return (v);
}
std::deque<int>	PmergeMe::getDeque()
{
	return (d);
}

int	PmergeMe::getSize()
{
	return size;
}
