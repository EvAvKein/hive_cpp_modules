/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:41:11 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 15:56:42 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc < 2)
	{
		std::cerr << CLR_BOLD
			"Harl needs something to complain about! ^^'"
		CLR_RESET << std::endl;
		return EXIT_FAILURE;
	}
	
	if (argc > 2)
	{
		std::cerr << CLR_BOLD
			"Harl is overwhelmed, one thing at a time please? :$"
		CLR_RESET << std::endl;
		return EXIT_FAILURE;
	}

	harl.complain(argv[1]);

	return EXIT_SUCCESS;
}
