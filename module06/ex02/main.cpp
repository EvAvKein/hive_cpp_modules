/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/27 15:43:45 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	Base* letter;
	try {
		std::cout << "Generating letter..." << std::endl;
		letter = generate();
	} catch (std::bad_alloc& e) {
		std::cout << "Couldn't allocate for letter :(" << std::endl;
		return EXIT_FAILURE;
	} catch (...) {
		std::cout << "Mystery error :(" << std::endl;
	};

	std::cout << "Identified by address: ";
	identify(letter);
	std::cout << "Identified by reference: ";
	identify(*letter);

	delete letter;

	return EXIT_SUCCESS;
}
