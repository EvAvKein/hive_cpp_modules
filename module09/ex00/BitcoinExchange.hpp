/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <chrono>
#include <regex>
#include <iomanip>

class BitcoinExchange
{
private:
	inline static const std::string rateHistoryFilePath = "data.csv";
	std::ifstream rateHistory;
	std::ifstream priceQueries;
	std::map<unsigned long long, double> priceDatabase;

	inline static const std::string datePattern = R"(\d{4}-\d{2}-\d{2})";
	inline static const std::string valuePattern = R"(\d+(\.\d+)?)";

	void loadRatesFromFile(std::ifstream &file);
	void printQueriesResults(std::ifstream &file);

	bool validDate(const std::string &dateStr);
	unsigned long long parseDate(std::string dateStr, size_t &lineNum);
	double parseRate(std::string rateStr, size_t &lineNum);

	class InvalidFileException : public std::runtime_error
	{
	public:
		InvalidFileException(void) = delete;
		InvalidFileException(size_t lineNum, std::string errorText);
		InvalidFileException(InvalidFileException const &copied) = delete;
		InvalidFileException &operator=(InvalidFileException const &assigned) = delete;
		~InvalidFileException(void) = default;
	};

public:
	BitcoinExchange(void) = delete;
	BitcoinExchange(BitcoinExchange const &copied) = delete;
	BitcoinExchange &operator=(BitcoinExchange const &assigned) = delete;
	~BitcoinExchange(void);

	BitcoinExchange(std::string const &priceQueriesFilePath);
};

#endif
