/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:04:35 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 15:50:04 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): name("Zombie")
{
}

void Zombie::set_name(std::string new_name)
{
	name = new_name;
}

void Zombie::announce(void)
{
	std::cout <<
		CLR_GRNBOLD << name <<
		CLR_RESET ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout <<
		CLR_DIMGRNBOLD << name << CLR_RESET
		CLR_DIMRED " destroyed..." CLR_RESET
	<< std::endl;
}
