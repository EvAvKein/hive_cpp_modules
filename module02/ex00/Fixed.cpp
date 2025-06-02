/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:58 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/02 21:56:21 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	this->value = 0;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

int Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	return this->value = raw;
}
