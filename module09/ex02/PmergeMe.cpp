/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/25 13:23:55 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> argvToIntVector(int argc, char **argv)
{
	std::vector<int> vector;
	for (int i = 1; i < argc; ++i)
	{
		std::string_view arg = argv[i];

		if (arg.length() == 0)
			throw std::invalid_argument("Error: Empty argument provided at argument of index " + std::to_string(i));

		if (arg.find_first_not_of("+0123456789") != arg.npos)
			throw std::invalid_argument("Error: Invalid positive number input at argument of index " + std::to_string(i));

		size_t plusIndex = arg.find_last_of("-+");
		if (plusIndex != arg.npos && plusIndex != 0)
			throw std::invalid_argument("Error: Misplaced sign character at argument of index " + std::to_string(i));

		vector.push_back(std::stoi(arg.data()));
	}
	return vector;
}