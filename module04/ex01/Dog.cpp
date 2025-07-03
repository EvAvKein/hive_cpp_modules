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
#include "Brain.hpp"

Dog::Dog(void): Animal("Dog")
{
	brain = new Brain();
}

Dog::Dog(const Dog &copied): Animal(copied)
{
	brain = new Brain(*copied.brain);
}

Dog &Dog::operator=(const Dog &assigned)
{
	Animal::operator=(assigned);
	delete brain;
	brain = new Brain();
	brain = assigned.brain;
	return (*this);
}

Dog::~Dog(void)
{
	delete brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof! Rrrrrruff! " << std::endl;
}
