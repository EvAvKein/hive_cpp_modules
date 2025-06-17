/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:22:41 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/16 14:45:11 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	name("CL4P-TP"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout <<
		"Default ClapTrap " << name << " constructed!"
	<< std::endl;
}

ClapTrap::ClapTrap(std::string name):
	name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout <<
		"ClapTrap " << name << " constructed!"
	<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copied)
{
	if (this != &copied)
		*this = copied;
	std::cout <<
		name << " copied ClapTrap " << copied.name << "!"
	<< std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assigned)
{
	if (this != &assigned)
		*this = assigned;
	std::cout
		<< name << " assigned to ClapTrap " << assigned.name << "!"
	<< std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout <<
		"ClapTrap " << name << " destroyed..."
	<< std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout <<
			name << " is " << (!hitPoints ? "dead" : "out of energy") <<
			" - cannot attack!"
		<< std::endl;
		return ;
	}
	energyPoints--;
	std::cout <<
		name << " attacks " << target <<
		", causing " << attackDamage << " points of damage!"
	<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout <<
		name << " received " << amount << " points of damage! " << 
		name << " now has " << hitPoints << " health"
	<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout <<
			name << " is " <<
			(!hitPoints ? "dead" : "out of energy") <<
			" - cannot repair!"
		<< std::endl;
		return ;
	}
	energyPoints--;
	if (hitPoints + amount < hitPoints)
	{
		hitPoints = 0;
		hitPoints--;
	}
	else
		hitPoints += amount;
	std::cout <<
		name << " repaired for " << amount << " points of damage! " <<
		name << " now has " << hitPoints << " health"
	<< std::endl;
}
