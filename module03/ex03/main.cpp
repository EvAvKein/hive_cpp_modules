/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:02 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/25 20:10:08 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main (void)
{

	std::cout << std::endl;
	{
		DiamondTrap guardTrap("GU4RD-TP");
		std::string target = "FR4G-TP";
		DiamondTrap fragTrap("FR4G-TP");

		guardTrap = fragTrap;
	}
	std::cout << std::endl;
	{
		DiamondTrap defaultTrap;
		
		defaultTrap.beRepaired(32);
		defaultTrap.takeDamage(41);
	}
	std::cout << std::endl;
	{
		DiamondTrap attackTrap("4TT4CK-TP");
		std::string target = "T4RG3T-TP";
		DiamondTrap targetTrap(target);
		
		attackTrap.attack(target);
		targetTrap.takeDamage(10);
	}
	std::cout << std::endl;
	{
		DiamondTrap tiredTrap("T1R3D-TP");
		
		for (int i = 50; i ; i--)
			tiredTrap.attack("the Vault Hunter");
		
		tiredTrap.attack("tiredness");
		tiredTrap.beRepaired(404);
	}
	std::cout << std::endl;
	{
		DiamondTrap healthyTrap("H34LTHY-TP");
		
		healthyTrap.beRepaired(-1);
	}
	std::cout << std::endl;
	{
		DiamondTrap deadTrap("D34D-TP");
		
		deadTrap.takeDamage(99);

		deadTrap.attack("death");
		deadTrap.beRepaired(404);
	}
	std::cout << std::endl;
	{
		ScavTrap guardTrap("GU4RD-TP");
		std::string target = "FR4G-TP";
		DiamondTrap fragTrap("FR4G-TP");
		
		guardTrap.guardGate();
		fragTrap.highFivesGuys();
		guardTrap.guardGate();
		fragTrap.highFivesGuys();
		guardTrap.attack("FR4G-TP");
		fragTrap.takeDamage(5);
		fragTrap.beRepaired(5);
		fragTrap.highFivesGuys();
	}
	std::cout << std::endl;
	{
		DiamondTrap deadTrap("FR13NDLY-TP");
			
		deadTrap.whoAmI();
	}
}
