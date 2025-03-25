/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:36:30 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/25 15:07:21 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <cctype> // already included in iostream, but isn't included on older systems/compilers
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
		std::cout << "* LOUD AND UNBEARABLE PHONEBOOK NOISE *"
		<< "\n(No args, \"" << argv[0] << "\" is good enough ^^)" << std::endl;
		
	PhoneBook phonebook = PhoneBook();
	std::string input;
	while (std::getline(std::cin, input))
	{
		if (!input.compare("ADD"))
		{
			phonebook.add_contact();
		}
		else if (!input.compare("SEARCH"))
		{
			phonebook.search_contacts();
		}
		else if (!input.compare("EXIT"))
		{
			std::cout << "Exiting phonebook!" << std::endl;
			return (EXIT_SUCCESS);
		}
		else
			std::cout
				<< "This phonebook can only \"ADD\", \"SEARCH\", or \"EXIT\"!"
			<< std::endl;	
	}
	return EXIT_FAILURE;
}
