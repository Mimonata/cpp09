/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:50 by spitul            #+#    #+#             */
/*   Updated: 2026/01/05 21:49:32 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <stdexcept>
#include <algorithm>

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
	len = v.size();
}

PmergeMe::PmergeMe(const PmergeMe &rh) : v(rh.v), d(rh.d), len(rh.len)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe &rh)
{
	if (this != &rh)
	{
		v = rh.v;
		d = rh.d;
		len = rh.len;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void	jacobsChain(std::vector<int> &jacob, int max)
{
	int	size;
	
	jacob.push_back(1);
	if (max <= 1)
		return;
	jacob.push_back(1);
	while (jacob.back() < max)
	{
		size = jacob.size();
		jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
	}
}

void	PmergeMe::PmergeMeSort()
{
	
	std::cout << "Before: " << *this;
	sortVector(v, len);
	sortDeque();
	std::cout << "After: " << *this;
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
		main.push_back(pairs[i].large);
		
	sortVector(main, size / 2);
	insertPend(main, pairs, last);
	v.clear();
	for (size_t i = 0; i < main.size(); i++)
		v.push_back(main[i]);
}

void	PmergeMe::sortDeque()
{}

void	PmergeMe::insertPend(std::vector<int> &main, std::vector<pair> &pairs, int last)
{
	std::vector<int>	jacob;
	std::vector<int>::iterator	pos;
	std::vector<int>::iterator	vit;
	
	std::vector<pair>::iterator	it = find_if(pairs.begin(), pairs.end(), findLarge(main[0]));
	if (it != pairs.end())
		main.insert(main.begin(),(*it).small);
	pairs.erase(it);
	jacobsChain(jacob, pairs.size());
	
	for (size_t j = 0; j < jacob.size(); j++)
	{
		if (j == 0)
		{
			vit = find(main.begin(), main.end(), pairs[j].large);
			pos = std::lower_bound(main.begin(), vit, pairs[j].small);
			main.insert(pos, pairs[j].small);
			continue;
		}
		for (int k = jacob[j]; k > jacob[j - 1]; k --)
		{
			vit = find(main.begin(), main.end(), pairs[k - 1].large); //dis wrong - i need to look at the indices in the pend - though i could also explore this to see how it works
			pos = std::lower_bound(main.begin(), vit, pairs[k - 1].small);
			main.insert(pos, pairs[k - 1].small);
		}
	}	
	if (last > -1)
	{
		pos = std::lower_bound(main.begin(), main.end(), last);
		main.insert(pos, last);
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
			os << ", ";
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
	return len;
}
