/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:48:00 by spitul            #+#    #+#             */
/*   Updated: 2026/01/02 23:01:43 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
	private:
	
		struct pair
		{
			int	large;
			int	small;
		};
		
		std::vector<int>	v;
		std::deque<int>		d;
		int					size;

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &rh);
		PmergeMe &operator=(const PmergeMe &rh);
		~PmergeMe();

		void	PmergeMeSort();
		void	sortVector();
		void	sortDeque();
};

#endif
