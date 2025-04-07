/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:41:11 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 10:59:22 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc < 2)
	{
		std::cerr << "Harl needs something to complain about! ^^'" << std::endl;
		return EXIT_FAILURE;
	}
	
	if (argc > 2)
	{
		std::cerr << "Harl is overwhelmed, one complaint level at a time please? :$" << std::endl;
		return EXIT_FAILURE;
	}

	harl.complain(argv[1]);

	return EXIT_SUCCESS;
}
