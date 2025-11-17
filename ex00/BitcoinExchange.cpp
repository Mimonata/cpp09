/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:09:38 by spitul            #+#    #+#             */
/*   Updated: 2025/11/17 06:33:38 by spitul           ###   ########.fr       */
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

void	BitcoinExchange::parseLine(std::string line, char delim)
{
	size_t	pos = line.find(delim);
	if (pos == line.npos)
	{
		std::cout << "Error: invalid input => " << line;
		return;
	}
	validateDate();
	validateValue();
}

void	BitcoinExchange::loadRates()
{
	std::string	line;
	std::ifstream	db("data.csv");
	
	if (!db.is_open())
	{
		std::cout << GYL << "Error while opening file\n" << RST;
		return ;
	}
	while (std::getline(db, line))
	{
		if (line.empty())
			continue;
		parseLine(line);
	}
}
