/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:20:52 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 10:23:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 0)
	{
		std::cerr << "ERROR: Negative zombieHorde is not possible!\n" << std::endl;
		throw ;
	}
	
	Zombie* horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	
	return horde;
}
