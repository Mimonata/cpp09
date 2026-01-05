/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobs.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:45:57 by spitul            #+#    #+#             */
/*   Updated: 2026/01/04 11:23:55 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

int	getJacobsNb(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	// else if (n == 2)
	// 	return 1;
	else
		return(getJacobsNb(n - 1) + 2 * getJacobsNb(n - 2));
}

void	jacobsChain(std::vector<int> &jacob, int len)
{
	for (int i = 2; i < len + 2; i++)
		jacob.push_back(getJacobsNb(i));
}

int main()
{
	std::vector<int> j;
	
	jacobsChain(j, 20);
	for(int i = 0; i < 20; i++)
		std::cout << j[i] << " ";
	std::cout << std::endl;
	return 0;
}
