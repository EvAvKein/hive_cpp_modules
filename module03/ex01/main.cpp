/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:02 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/16 14:34:58 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
	{
		ScavTrap defaultTrap;
		
		defaultTrap.beRepaired(32);
		defaultTrap.takeDamage(41);
	}
	std::cout << std::endl;
	{
		ScavTrap attackTrap("4TT4CK-TP");
		std::string target = "T4RG3T-TP";
		ScavTrap targetTrap(target);
		
		attackTrap.attack(target);
		targetTrap.takeDamage(10);
	}
	std::cout << std::endl;
	{
		ScavTrap tiredTrap("T1R3D-TP");
		
		for (int i = 50; i ; i--)
			tiredTrap.beRepaired(1);
		
		tiredTrap.attack("tiredness");
		tiredTrap.beRepaired(404);
	}
	std::cout << std::endl;
	{
		ScavTrap healthyTrap("H34LTHY-TP");
		
		healthyTrap.beRepaired(-1);
	}
	std::cout << std::endl;
	{
		ScavTrap deadTrap("D34D-TP");
		
		deadTrap.takeDamage(99);

		deadTrap.attack("death");
		deadTrap.beRepaired(404);
	}
	std::cout << std::endl;
	{
		ScavTrap guardTrap("GU4RD-TP");
		
		guardTrap.guardGate();
	}
}
