/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:02 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/16 14:37:17 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	{
		FragTrap defaultTrap;
		
		defaultTrap.beRepaired(32);
		defaultTrap.takeDamage(41);
	}
	std::cout << std::endl;
	{
		FragTrap attackTrap("4TT4CK-TP");
		std::string target = "T4RG3T-TP";
		FragTrap targetTrap(target);
		
		attackTrap.attack(target);
		targetTrap.takeDamage(10);
	}
	std::cout << std::endl;
	{
		FragTrap tiredTrap("T1R3D-TP");
		
		for (int i = 100; i ; i--)
			tiredTrap.attack("the Vault Hunter");
		
		tiredTrap.attack("tiredness");
		tiredTrap.beRepaired(404);
	}
	std::cout << std::endl;
	{
		FragTrap healthyTrap("H34LTHY-TP");
		
		healthyTrap.beRepaired(-1);
	}
	std::cout << std::endl;
	{
		FragTrap deadTrap("D34D-TP");
		
		deadTrap.takeDamage(99);

		deadTrap.attack("death");
		deadTrap.beRepaired(404);
	}
	std::cout << std::endl;
	{
		ScavTrap guardTrap("GU4RD-TP");
		std::string target = "FR4G-TP";
		FragTrap fragTrap("FR4G-TP");
		
		guardTrap.guardGate();
		fragTrap.highFivesGuys();
		guardTrap.guardGate();
		fragTrap.highFivesGuys();
		guardTrap.attack("FR4G-TP");
		fragTrap.takeDamage(5);
		fragTrap.beRepaired(5);
		fragTrap.highFivesGuys();
	}
}
