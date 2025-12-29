/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:09:38 by spitul            #+#    #+#             */
/*   Updated: 2025/12/29 22:49:36 by spitul           ###   ########.fr       */
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
		rates = rh.rates;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rh)
{
	if (this != &rh)
		rates = rh.rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::trim(std::string &str)
{
	std::string	ws = " \t\r\b";
	std::string::iterator	it = str.begin();
	std::string::reverse_iterator	rit=str.rbegin();
	
	for (it; it != str.end(); it++)
	{
		if (ws.find(*it) != std::string::npos)
		{
			str = str.substr(it - str.begin());
			break;
		}
	}
	for(rit; rit != str.rend(); rit++)
	{
		if (ws.find(*rit) != std::string::npos)
		{
			str = str.substr(0, str.rend() - rit);
			break;
		}
	}
}

bool	BitcoinExchange::validateDate(std::string &date)
{
	trim(date);
	
}

bool	BitcoinExchange::validateValue(std::string &str)
{
	
}

void	BitcoinExchange::parseLine(std::string line, char delim)
{
	size_t	pos = line.find(delim);
	if (pos == line.npos)
	{
		std::cout << "Error: invalid input => " << line;
		return;
	}

	std::string	date = line.substr(0, pos);
	std::string	value = line.substr(pos + 1);
	validateDate(date);
	validateValue(value);
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
		parseLine(line, ',');
	}
}
