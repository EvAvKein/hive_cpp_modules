/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:38:22 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:07:48 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
}

Dog::Dog(const Dog &copied): Animal(copied)
{
}

Dog &Dog::operator=(const Dog &assigned)
{
	Animal::operator=(assigned);
	return (*this);
}

Dog::~Dog(void)
{
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof! Rrrrrruff! " << std::endl;
}
