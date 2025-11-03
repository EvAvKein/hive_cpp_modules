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

BitcoinExchange::BitcoinExchange(std::string const& priceQueryFilePath)
{
	if (std::regex_match(priceQueryFilePath, std::regex(".csv$")))
		throw std::invalid_argument(
			"Program argument must be a file ending with \".csv\"");
	rateHistory = new std::ifstream(BitcoinExchange::rateHistoryFilePath);

}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &copied)
// {
// 	std::cout <<
// 		"Corporate is hiring a bureaucrat who's exactly like " << name <<
// 		" (including grade " << grade << ")" <<
// 		". Corporate really likes " << name << " apparently."
// 	<< std::endl;
// }

BitcoinExchange::~BitcoinExchange(void)
{
}

// std::ostream	&operator<<(std::ostream &ostream, BitcoinExchange &output)
// {
// 	ostream <<
// 		output.getName() <<
// 		", bureaucrat grade " << bureaucrat.getGrade() << "."
// 	<< std::endl;
// 	return ostream;
// }
