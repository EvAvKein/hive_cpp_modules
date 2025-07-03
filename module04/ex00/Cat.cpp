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

Cat::Cat(void): Animal("Cat")
{
}

Cat::Cat(const Cat &copied): Animal(copied)
{
}

Cat &Cat::operator=(const Cat &assigned)
{
	Animal::operator=(assigned);
	return (*this);
}

Cat::~Cat(void)
{
}

void Cat::makeSound(void) const
{
	std::cout << "Meow. Purrr." << std::endl;
}

