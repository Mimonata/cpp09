/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:19:19 by spitul            #+#    #+#             */
/*   Updated: 2026/01/01 19:25:29 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong input.\nTry ./RPN \"RPN sequence\"\n" << std::endl;
		return 1;
	}

	try 
	{
		RPN rpn(av[1]);
		std::cout << rpn.getResult() << std::endl; 
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
