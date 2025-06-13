/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:58 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/13 10:02:54 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ORTHODOX CANONICAL FORM

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	if (_bits <= 0)
		throw std::out_of_range(
			"Fixed was set to an invalid amount of fractional bits"
		);
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &fixed)
		*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// CONSTRUCTORS WITH VALUE

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << _bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _bits));
}

// CONVERSION METHODS

float Fixed::toFloat(void) const
{
	return static_cast<float>(toInt())
			+ static_cast<float>(toFractionalValue()) / pow(2, _bits);
}

int Fixed::toInt(void) const
{
	return this->getRawBits() >> _bits;
}

// INSERTION OVERLOAD

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// GETTER & SETTER

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

// CUSTOM

int Fixed::getFixedIntMax(void) const
{
	static int fixedIntMax = static_cast<int>(
		((~0 ^ (static_cast<unsigned int>(1) << std::numeric_limits<int>::digits))
			<< _bits) >> _bits);
	return fixedIntMax;
}

int Fixed::toFractionalValue(void) const
{
	return _value & static_cast<int>(pow(2, _bits) - 1);
}

void Fixed::printRawBits(void)
{
	int byteSize = std::numeric_limits<unsigned char>::digits;
	int i = sizeof(int) * byteSize;
	unsigned char chr;
    
	while (i)
	{
		chr = ((this->_value >> --i) & 1) + '0';
		std::cout << chr;
		if (!(i % (byteSize / 2)))
			std::cout << " ";
		if (!(i % byteSize) && i >= byteSize)
			std::cout << "| ";
	}
	std::cout << std::endl;
}
