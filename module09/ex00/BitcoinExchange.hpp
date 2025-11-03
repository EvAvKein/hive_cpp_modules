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
# define BITCOIN_EXCHANGE_HPP

# include <stdexcept>
# include <iostream>
# include <fstream>
# include <map>
# include <chrono>
# include <regex>

struct time {};

class BitcoinExchange
{
	private:
		inline static const std::string		rateHistoryFilePath = "data.csv";
		std::ifstream								*rateHistory = nullptr;
		std::ifstream								*priceQuery = nullptr;
		std::map<, int>	output;

	public:
		BitcoinExchange(void) = delete;
		BitcoinExchange(std::string const& priceQueryFilePath);
		BitcoinExchange(BitcoinExchange const& copied);
		BitcoinExchange &operator=(BitcoinExchange const& assigned) = delete;
		~BitcoinExchange(void);
};

std::ostream	&operator<<(std::ostream &ostream, BitcoinExchange &output);

#endif
