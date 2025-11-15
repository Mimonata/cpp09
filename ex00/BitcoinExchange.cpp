/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:09:38 by spitul            #+#    #+#             */
/*   Updated: 2025/11/15 08:03:58 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{}
		
BitcoinExchange::BitcoinExchange(const BitcoinExchange &rh)
{
	if (this != &rh)
	
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rh)
{}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::loadRates()
{
	std::ifstream	db("data.csv");
	
	if (!db.is_open())
	{
		std::cout << GYL << "Error while opening file\n" << RST;
		return ;
	}
	while (!db.eof())
	{
		std::string	line = getline()
	}
}
