/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:48:00 by spitul            #+#    #+#             */
/*   Updated: 2026/01/05 08:41:07 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>

class PmergeMe
{
	private:
	
		struct pair
		{
			int	large;
			int	small;
		};
		
		struct findLarge
		{
			int	val;
			findLarge(int v) : val(v) {}
			bool	operator()(const pair &p)
			{
				return (p.large == val);
			}
		};
		
		std::vector<int>	v;
		std::deque<int>		d;
		int					len;

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &rh);
		PmergeMe &operator=(const PmergeMe &rh);
		~PmergeMe();

		void	PmergeMeSort();
		void	sortVector(std::vector<int> &v, int size);
		void	sortDeque();
		void	insertPend(std::vector<int> &main, std::vector<pair> &pairs, int last);

		std::vector<int>	getVector();
		std::deque<int>		getDeque();
		int					getSize();

		
};

std::ostream	&operator<<(std::ostream &os, PmergeMe &obj);

#endif
