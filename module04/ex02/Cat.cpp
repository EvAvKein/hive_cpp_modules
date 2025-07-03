/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:38:22 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/29 17:29:12 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void): Animal("Cat")
{
	brain = new Brain();
}

Cat::Cat(const Cat &copied): Animal(copied)
{
	brain = new Brain(*copied.brain);
}

Cat &Cat::operator=(const Cat &assigned)
{
	Animal::operator=(assigned);
	delete brain;
	brain = new Brain();
	brain = assigned.brain;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow. Purrr." << std::endl;
}
