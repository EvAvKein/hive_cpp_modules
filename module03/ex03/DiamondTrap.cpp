/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:11:54 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/16 14:47:41 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	name = "D14M0ND-TP";
	ClapTrap::name = name.append("_clap_name");
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	
	std::cout <<
		"Default DiamondTrap " << name << " constructed!"
	<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	
	std::cout <<
		"DiamondTrap " << name << " constructed!"
	<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copied)
{
	if (this != &copied)
		*this = copied;
	std::cout << "DiamondTrap "
		<< name << " copied ClapTrap " << copied.name << "!"
	<< std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &assigned)
{
	if (this != &assigned)
		*this = assigned;
	std::cout <<
		"DiamondTrap " << name << " assigned to ClapTrap " << assigned.name << "!"
	<< std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout <<
		"DiamondTrap " << name << " destroyed..."
	<< std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout <<
		"I'm " << ClapTrap::name << ", but you can call me " << name << "!"
	<< std::endl;
}
