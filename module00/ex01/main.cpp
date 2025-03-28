/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:36:30 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/28 12:27:11 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <cctype> // already included in iostream, but isn't included on older systems/compilers
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
		std::cout << CLR_DIMBOLD "* LOUD AND UNBEARABLE PHONEBOOK NOISE *\n" CLR_RESET
		CLR_DIM "(No args, \"" << argv[0] << "\" is good enough ^^)" CLR_RESET << std::endl;
		
	PhoneBook phonebook = PhoneBook();
	std::string input;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
		{
			if (!phonebook.add_contact())
			{
			 	std::cout << "Exiting phonebook!" << std::endl;
				return EXIT_SUCCESS;
			}
		}
		else if (input == "SEARCH")
		{
			phonebook.search_contacts();
		}
		else if (input == "EXIT")
		{
			std::cout << "Exiting phonebook!" << std::endl;
			return EXIT_SUCCESS;
		}
		else
			std::cerr <<
				CLR_REDBOLD "This phonebook can only "
				CLR_GREENBOLD "ADD" CLR_RESET CLR_REDBOLD ", " CLR_RESET
				CLR_GREENBOLD "SEARCH" CLR_RESET CLR_REDBOLD ", or " CLR_RESET
				CLR_GREENBOLD "EXIT" CLR_RESET CLR_REDBOLD "!" CLR_RESET
			<< std::endl;	
	}
	return EXIT_FAILURE;
}
