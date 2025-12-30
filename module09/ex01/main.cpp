/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:02:01 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/19 11:03:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Program must receive exactly 1 argument" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		int result = reversePolishNotation(argv[1]);
		std::cout << result << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
