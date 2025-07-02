/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:22:41 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:05:16 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("[GENERIC ANIMAL]")
{
	std::cout << "A default " << type << " is here! :D" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "A " << type << " is here! :D"<< std::endl;
}

Animal::Animal(const Animal &copied): type("Animal")
{
	std::cout <<
		"We're making a copy of " << copied.type << "! :o"
	<< std::endl;
	if (this != &copied)
		*this = copied;
}

Animal &Animal::operator=(const Animal &assigned)
{
	std::cout <<
		"Our " << type << " is being assigned to a " << assigned.type << "! :O"
	<< std::endl;
	if (this != &assigned)
		type = assigned.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Our " << type << " is leaving! D:" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "[INCOMPREHENSIBLE GENERIC ANIMAL NOISES]" << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}
