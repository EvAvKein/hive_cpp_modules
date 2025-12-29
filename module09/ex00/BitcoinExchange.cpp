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
	if (!rateHistory.is_open())
		throw std::invalid_argument(
			std::string("Program unable to open \"") + BitcoinExchange::rateHistoryFilePath + "\" Bitcoin rates file.");

	priceQueries = std::ifstream(priceQueriesFilePath);
	if (!priceQueries.is_open())
		throw std::invalid_argument(
			std::string("Program unable to open \"") + priceQueriesFilePath + "\" Bitcoin rates file.");

	loadRatesFromFile(rateHistory);
	printQueriesResults(priceQueries);
}

void BitcoinExchange::loadRatesFromFile(std::ifstream &ratesFile)
{
	std::string line;
	size_t lineNum = 0;
	static const std::string header = "date,exchange_rate";

	std::getline(ratesFile, line);
	if (line != header)
		throw InvalidFileException(lineNum, "Rates file must begin with \"" + header + "\"");
	else
		lineNum++;

	std::string patternStr = "^" + datePattern + "," + valuePattern + "$";
	static const std::regex rateRegex(patternStr);

	while (getline(ratesFile, line))
	{
		if (!std::regex_match(line, rateRegex))
			throw InvalidFileException(lineNum, "Rates file must comply with pattern /" + patternStr + "/\n" + line);

		std::string dateStr = line.substr(0, line.find(','));
		unsigned long long date = parseDate(dateStr, lineNum);

		std::string rateStr = line.substr(line.find(',') + 1);
		double rate = parseRate(rateStr, lineNum);

		if (priceDatabase.contains(date))
			throw InvalidFileException(lineNum, "Duplicate rate entry for the provided date  => " + dateStr);
		priceDatabase[date] = rate;

		lineNum++;
	}
	if (lineNum < 2)
		throw InvalidFileException(lineNum, "Rates file must have at least one entry");
}

void BitcoinExchange::printQueriesResults(std::ifstream &queries)
{
	std::string line;
	size_t lineNum = 0;
	static const std::string header = "date | value";

	std::getline(queries, line);
	if (line != header)
		throw InvalidFileException(lineNum, "Input file must begin with \"" + header + "\"");
	else
		lineNum++;

	std::string patternStr = "^" + datePattern + " \\| " + valuePattern + "$";
	static const std::regex rateRegex(patternStr);
	while (getline(queries, line))
	{
		if (!std::regex_match(line, rateRegex))
		{
			std::cout << InvalidFileException(lineNum++, "Not compliant with pattern /" + patternStr + "/ => " + line).what() << '\n';
			continue;
		}

		std::string dateStr = line.substr(0, line.find(' '));
		unsigned long long date = parseDate(dateStr, lineNum);

		std::string quantityStr = line.substr(line.find_last_of(' ') + 1);
		double quantity = parseRate(quantityStr, lineNum);

		if (quantity > 1000.0)
		{
			std::cout << InvalidFileException(lineNum, "Value above 1000.0").what() << '\n';
			continue;
		}

		static const unsigned long long firstDate = priceDatabase.begin()->first;
		static const unsigned long long lastDate = priceDatabase.rbegin()->first;

		if (date >= lastDate)
			date = lastDate;
		else
		{
			while (date >= firstDate)
			{

				if (priceDatabase.contains(date))
					break;
				--date;
			}
		}

		if (date < firstDate)
			std::cout << "Error: Date is prior to earliest data => " << dateStr << '\n';
		else
			std::cout << dateStr << " => " << quantity << " = " << quantity * priceDatabase[date] << '\n';

		lineNum++;
	}
	std::cout << std::flush;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (rateHistory.is_open())
		rateHistory.close();
	if (priceQueries.is_open())
		priceQueries.close();
}

BitcoinExchange::InvalidFileException::InvalidFileException(size_t lineNum, std::string errorText) : runtime_error(std::string("Error (line ") + std::to_string(lineNum) + "): " + errorText)
{
}

unsigned long long BitcoinExchange::parseDate(std::string dateStr, size_t &lineNum)
{
	if (!validDate(dateStr))
		throw InvalidFileException(lineNum, "Impossible date => " + dateStr);
	dateStr.erase(std::remove(dateStr.begin(), dateStr.end(), '-'), dateStr.end());
	unsigned long long date;
	try
	{
		date = std::stoull(dateStr);
	}
	catch (std::out_of_range &e)
	{
		throw InvalidFileException(lineNum, "Date exceeds representable value");
	}
	return date;
}

double BitcoinExchange::parseRate(std::string rateStr, size_t &lineNum)
{
	double rate;
	try
	{
		rate = std::stod(rateStr);
	}
	catch (std::out_of_range &e)
	{
		throw InvalidFileException(lineNum, "Rate exceeds representable value");
	}
	return rate;
}

bool BitcoinExchange::validDate(const std::string &dateStr)
{
	std::istringstream istream{dateStr};
	std::tm tm = {};

	istream >> std::get_time(&tm, "%Y-%m-%d");
	if (istream.fail())
		return false;

	// <chrono> and <iomanip>'s tm represent time differently
	std::chrono::year_month_day chrono_tm{
		std::chrono::year{tm.tm_year + 1900},
		std::chrono::month{static_cast<unsigned int>(tm.tm_mon + 1)},
		std::chrono::day{static_cast<unsigned int>(tm.tm_mday)}};

	return chrono_tm.ok();
}
