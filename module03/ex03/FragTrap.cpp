/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:11:54 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/16 14:49:31 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "FR4G-TP";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	
	std::cout <<
		"Default FragTrap " << name << " constructed!"
	<< std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	
	std::cout <<
		"FragTrap " << name << " constructed!"
	<< std::endl;
}

FragTrap::FragTrap(const FragTrap &copied)
{
	if (this != &copied)
		*this = copied;
	std::cout <<
		"FragTrap " << name << " copied FragTrap " << copied.name << "!"
	<< std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &assigned)
{
	if (this != &assigned)
		*this = assigned;
	std::cout << 
		"FragTrap " << name << " assigned to FragTrap " << assigned.name << "!"
	<< std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout <<
		"FragTrap " << name << " destroyed..."
	<< std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout <<
		"FragTrap " << name << " wants some high fives, guys :D"
	<< std::endl;
}
