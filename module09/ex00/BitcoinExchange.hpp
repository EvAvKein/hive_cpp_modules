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
#include <iostream>
#include <fstream>
#include <map>
#include <chrono>
#include <regex>
#include <iomanip>

struct time
{
};

class BitcoinExchange
{
private:
	inline static const std::string rateHistoryFilePath = "data.csv";
	std::ifstream rateHistory;
	std::ifstream priceQueries;
	std::map<uint64_t, float> priceDatabase;

	inline static const std::string datePattern = R"(\\d{4}-\\d{2}-\\d{2})";
	inline static const std::string valuePattern = R"(\\d+(\\.\\d+)?)";

	void loadRatesFromFile(std::ifstream &file);
	void printQueriesResults(std::ifstream &file);

public:
	BitcoinExchange(void) = delete;
	BitcoinExchange(BitcoinExchange const &copied) = delete;
	BitcoinExchange &operator=(BitcoinExchange const &assigned) = delete;
	~BitcoinExchange(void);

	BitcoinExchange(std::string const &priceQueriesFilePath);
};
#endif
