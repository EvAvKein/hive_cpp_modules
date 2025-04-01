/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:18:58 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 10:20:49 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombies_in_function_scope()
{
	Zombie zomb_in_stack("Stackie");
	zomb_in_stack.announce();
	
	Zombie* zomb_in_heap = newZombie("Heapie");

	return zomb_in_heap;
}

int main()
{
	Zombie firstZomb("Firstie");
	firstZomb.announce();
	
	Zombie secondZomb("Secondie");
	Zombie* thirdZomb;
	try {
		thirdZomb = newZombie("Thirdie");
	} catch (...) {
		std::cerr << "Can't allocate the a heap zombie (\"Thirdie\"), quitting!" << std::endl;
		return EXIT_FAILURE;
	}
	thirdZomb->announce();
	secondZomb.announce();
	
	randomChump("Chumpie");

	Zombie* heapZomb;
	try {
		heapZomb = zombies_in_function_scope();
	} catch (...) {
		std::cerr << "Can't allocate the a heap zombie (\"Heapie\"), quitting!" << std::endl;
		delete thirdZomb;
		return EXIT_FAILURE;
	}
	heapZomb->announce();
	
	delete heapZomb;
	delete thirdZomb;
	
	return EXIT_SUCCESS;
}