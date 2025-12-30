/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:09:38 by spitul            #+#    #+#             */
/*   Updated: 2025/12/30 23:45:33 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <stdexcept>
#include <cstdlib>

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

void	BitcoinExchange::trimWhitespace(std::string &str)
{
	size_t	first = str.find_first_not_of(" \t\r\b\n");
	if (first == std::string::npos)
	{
		str = "";
		return;
	}
	size_t	last = str.find_last_not_of(" \t\r\b\n");
	str = str.substr(first, last - first + 1);
}

bool	BitcoinExchange::validateDate(std::string &date, bool write_err)
{
	bool	valid = true;
	char	*end;
	
	trimWhitespace(date);
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		if (write_err)
			std::cout << KHI << "Error: bad input => " << date << RST << std::endl;
		return false;
	}
	std::string	y = date.substr(0, 4);
	long	year = std::strtol(y.c_str(), &end, 10);
	if (year < 2009 || year > 2026 || *end != '\0')
		valid = false;
	std::string	m = date.substr(5, 2);
	long	mon = std::strtol(m.c_str(), &end, 10);
	if (mon < 1 || mon > 12 || *end != '\0')
		valid = false;
	std::string	d = date.substr(8, 2);
	long	day = std::strtol(d.c_str(), &end, 10);
	if (day < 1 || day > 31 || *end != '\0')
		valid = false;
	if (mon <= 7 && mon % 2 == 0 && day > 30)
		valid = false;
	else if (mon > 7 && mon % 2 == 1 && day > 30)
		valid = false;
	if (mon == 2)
	{
		if (year % 4 == 0 && day > 29)
			valid = false;
		else if (year % 4 != 0 && day > 28)
			valid = false;
	}
	if (!valid && write_err)
		std::cout << "Error: bad input => " << date << std::endl;
	return valid;
}

bool	BitcoinExchange::validateValue(std::string &str, bool write_err, bool db)
{
	char	*end;
	
	trimWhitespace(str);
	double	val = std::strtod(str.c_str(), &end);
	if (val < 0 || *end != '\0')
	{
		if (write_err)
			std::cout << "Error: not a positive number\n";
		return false;
	}
	if (val > 1000 && !db)
	{
		if (write_err)
			std::cout << "Error: number too large\n";
		return false;
	}
	return true;
}

void	BitcoinExchange::parseDBLine(std::string line, bool write_err)
{
	size_t	pos = line.find(',');
	if (pos == line.npos)
	{
		if (write_err)
			std::cout << "Error: bad input => " << line;
		return;
	}

	std::string	date = line.substr(0, pos);
	std::string	value = line.substr(pos + 1);
	if (!validateDate(date, write_err) || !validateValue(value, write_err, true))
		return;
	rates[date] = std::atof(value.c_str());
}

void	BitcoinExchange::loadRates()
{
	std::string	line;
	std::ifstream	db("data.csv");
	
	if (!db.is_open())
	{
		std::cout << GYL << "Error while opening database\n" << RST;
		return ;
	}
	while (std::getline(db, line))
	{
		if (line.empty())
			continue;
		parseDBLine(line, false);
	}
	db.close();
}

double BitcoinExchange::getRate(std::string date)
{
	std::map<std::string, double>::iterator	it = rates.lower_bound(date);
	
	if(it != rates.end() && it->first == date)
		return it->second;
	
	if (it == rates.begin())
		return -1;
	
	--it;
	return it->second;
}

void	BitcoinExchange::processFile(std::ifstream &file)
{
	std::string	line;
	double	amount;
	double	rate;
	
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t	pos = line.find('|');
		if (pos == line.npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr(0, pos);
		std::string	value = line.substr(pos + 1);
		if (!validateDate(date, true) || !validateValue(value, true, false))
			continue;
		amount = std::atof(value.c_str());
		rate = getRate(date);
		if (rate > 0)
			std::cout << date << " => " << amount << " = " << rate * amount << std::endl;
	}
}
//2011-01-09 => 1 = 0.32