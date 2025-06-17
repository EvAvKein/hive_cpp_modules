/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:02 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/16 10:35:00 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	{
		ClapTrap defaultTrap;
		
		defaultTrap.beRepaired(32);
		defaultTrap.takeDamage(41);
	}
	std::cout << std::endl;
	{
		ClapTrap attackTrap("4TT4CK-TP");
		std::string target = "T4RG3T-TP";
		ClapTrap targetTrap(target);
		
		attackTrap.attack(target);
		targetTrap.takeDamage(10);
	}
	std::cout << std::endl;
	{
		ClapTrap tiredTrap("T1R3D-TP");
	
		tiredTrap.attack("the air");
		tiredTrap.beRepaired(2);
		tiredTrap.attack("a barrel");
		tiredTrap.beRepaired(4);
		tiredTrap.attack("their enemies");
		tiredTrap.beRepaired(6);
		tiredTrap.attack("their friends");
		tiredTrap.beRepaired(8);
		tiredTrap.attack("itself");
		tiredTrap.beRepaired(10);

		tiredTrap.attack("tiredness");
		tiredTrap.beRepaired(404);
	}
	std::cout << std::endl;
	{
		ClapTrap healthyTrap("H34LTHY-TP");
		
		healthyTrap.beRepaired(-1);
	}
	std::cout << std::endl;
	{
		ClapTrap deadTrap("D34D-TP");
		
		deadTrap.takeDamage(99);

		deadTrap.attack("death");
		deadTrap.beRepaired(404);
	}
}
