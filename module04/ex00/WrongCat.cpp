/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:38:22 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/29 17:29:12 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
}

WrongCat::WrongCat(const WrongCat &copied): WrongAnimal(copied)
{
}

WrongCat &WrongCat::operator=(const WrongCat &assigned)
{
	WrongAnimal::operator=(assigned);
	return (*this);
}

WrongCat::~WrongCat(void)
{
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong meow. Wrong purrr." << std::endl;
}

