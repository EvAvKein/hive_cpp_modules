/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:11:54 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/25 20:06:36 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "SC4V-TP";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	
	std::cout <<
		"Default ScavTrap " << name << " constructed!"
	<< std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	
	std::cout <<
		"ScavTrap " << name << " constructed!"
	<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copied)
{
	if (this != &copied)
		*this = copied;
	std::cout <<
		name << " copied ScavTrap " << copied.name << "!"
	<< std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assigned)
{
	if (this != &assigned)
	{
		name = assigned.name;
		hitPoints = assigned.hitPoints;
		energyPoints = assigned.energyPoints;
		attackDamage = assigned.attackDamage;
	}
	std::cout <<
		name << " assigned to ScavTrap " << assigned.name << "!"
	<< std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout <<
		"ScavTrap " << name << " destroyed..."
	<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout <<
		name << " is in Gatekeeper mode!"
	<< std::endl;
}
