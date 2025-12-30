/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:12:12 by spitul            #+#    #+#             */
/*   Updated: 2025/12/30 19:16:24 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream	file;
	BitcoinExchange	btc;
	
	if (argc != 2)
	{
		std::cout << DOR << "Expected input: GYL ./btc <infile>\n" << RST;
		return 1;
	}
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << DOR << "Error while opening input file\n";
		return 1;
	}
	btc.loadRates();
	btc.processFile(file);
	file.close();
	return 0;
}
