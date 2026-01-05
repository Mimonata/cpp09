/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:05 by spitul            #+#    #+#             */
/*   Updated: 2026/01/05 19:40:49 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Numerical arguments expected\n";
		return 1;
	}
	PmergeMe	obj(ac, av);
	std::cout << obj;
	obj.PmergeMeSort();
	return 0;
}
