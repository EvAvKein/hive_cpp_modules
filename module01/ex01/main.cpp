/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:18:58 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 15:49:41 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* horde;
	int N = 7;

	try {
		horde = zombieHorde(N, "Horder");
	} catch (...) {
		std::cerr << CLR_REDBOLD
			"Cancelling test after failed zombieHorde allocation..."
		CLR_RESET << std::endl;
		return EXIT_FAILURE;
	}
	
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	
	return EXIT_SUCCESS;
}
