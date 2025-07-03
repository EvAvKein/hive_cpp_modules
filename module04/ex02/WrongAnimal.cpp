/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:22:41 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:05:16 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("[GENERIC WRONG ANIMAL]")
{
	std::cout << "A default " << type << " is here! :D" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "A " << type << " is here! :D"<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copied): type("Animal")
{
	std::cout <<
		"We're making a copy of " << copied.type << "! :o"
	<< std::endl;
	if (this != &copied)
		*this = copied;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assigned)
{
	std::cout <<
		"Our " << type << " is being assigned to a " << assigned.type << "! :O"
	<< std::endl;
	if (this != &assigned)
		type = assigned.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Our " << type << " is leaving! D:" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "[INCOMPREHENSIBLE WRONG ANIMAL NOISES]" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}
