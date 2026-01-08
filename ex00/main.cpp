/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:12:12 by spitul            #+#    #+#             */
/*   Updated: 2026/01/08 16:14:05 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream	file;
	BitcoinExchange	btc;
	
	if (argc != 2)
	{
		std::cout << DOR << "Expected input: ./btc <infile>\n" << RST;
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
