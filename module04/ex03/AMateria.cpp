/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:22:41 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:05:16 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type)
{
	std::cout << "We made some " << type << " :>"<< std::endl;
}

AMateria::AMateria(const AMateria &copied): type("AMateria")
{
	std::cout <<
		"We're making a copy of our " << copied.type << " ~"
	<< std::endl;
	if (this != &copied)
		*this = copied;
}

AMateria &AMateria::operator=(const AMateria &assigned)
{
	std::cout <<
		"We're assigning our " << type << " to be " << assigned.type << " *_* "
	<< std::endl;
	if (this != &assigned)
		type = assigned.type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "The " << type << " is destroyed! ;_;" << std::endl;
}


std::string const & AMateria::getType(void) const
{
	return type;
}
