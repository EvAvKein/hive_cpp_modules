/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/25 13:23:55 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string const &priceQueriesFilePath)
{
	rateHistory = std::ifstream(BitcoinExchange::rateHistoryFilePath);
	if (rateHistory.is_open())
		throw std::invalid_argument(
			std::string("Program unable to open \"") + BitcoinExchange::rateHistoryFilePath + "\" Bitcoin rates file.");

	priceQueries = std::ifstream(priceQueriesFilePath);
	if (priceQueries.is_open())
		throw std::invalid_argument(
			std::string("Program unable to open \"") + priceQueriesFilePath + "\" Bitcoin rates file.");

	loadRatesFromFile(rateHistory);
}

void BitcoinExchange::loadRatesFromFile(std::ifstream &ratesFile)
{
	std::string line;
	static const std::string header = "date,exchange_rate";

	std::getline(ratesFile, line);
	if (line != header)
		throw std::runtime_error(std::string("Bitcoin rates CSV file must begin with \"") + header + "\"");

	while (getline(ratesFile, line))
	{
		static const std::regex ratePattern(datePattern + "," + valuePattern);
		if (!std::regex_match(line, ratePattern))
			;
	}
}

void BitcoinExchange::printQueriesResults(std::ifstream &queries)
{
	std::string line;
	static const std::string header = "date | value";

	std::getline(queries, line);
	if (line != "date | value")
		throw std::runtime_error(std::string("Bitcoin rates CSV file must begin with \"") + header + "\"");

	while (getline(queries, line))
	{
		static const std::regex ratePattern(datePattern + " | " + valuePattern);
		if (!std::regex_match(line, ratePattern))
			;
	}
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (rateHistory.is_open())
		rateHistory.close();
	if (priceQueries.is_open())
		priceQueries.close();
}

// std::ostream	&operator<<(std::ostream &ostream, BitcoinExchange &output)
// {
// 	ostream <<
// 		output.getName() <<
// 		", bureaucrat grade " << bureaucrat.getGrade() << "."
// 	<< std::endl;
// 	return ostream;
// }
