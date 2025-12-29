/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:05:59 by spitul            #+#    #+#             */
/*   Updated: 2025/11/17 19:59:33 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// Colors

#define GYL "\033[38;2;173;255;47m"
#define LIL "\033[38;2;200;162;200m"
#define DOR "\033[38;2;255;140;0m"
#define AGL "\033[38;2;255;191;0m"
#define KHI "\033[38;2;240;230;140m"
#define RST "\033[0m"

#include <map>
#include <string>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	rates;
		void	loadRates();
		void	parseLine(std::string line, char delim);
		bool	validateDate(std::string &str);
		bool	validateValue(std::string &str);
		void	trim(std::string &str);
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &rh);
		BitcoinExchange	&operator=(const BitcoinExchange &rh);
		~BitcoinExchange();
};

#endif
