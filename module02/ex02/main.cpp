/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:45 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/12 16:44:44 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * 
 * Bits layout:
 * 
 * 0b siii iiii | iiii iiii | iiii iiii | ffff ffff
 * 
 *   0b siii iiii | iiii iiii | iiii iiii | ffff ffff / 256
 *=> 0b s000 0000 | 0iii iiii | iiii iiii | iiii iiii
 *
 *   0b s000 0000 | 0iii iiii | iiii iiii | iiii iiii * 256
 *   0b siii iiii | iiii iiii | iiii iiii | 0000 0000
 *
 *			ff		    ff			ff			ff
 *   0b siii iiii | iiii iiii | ffff ffff | 0000 0000
 *
 * f = fractional value
 * s = sign
 * i = integer value 
 * 
 */

#if false

	/*
	The code below is provided by the instructions

	I'm aware that it causes a duplicate inclusion of <iostream>,
	but including that inclusion means I comply with the instructions to the letter.
	Good thing <iostream> has a header guard :)
	*/

	#include <iostream>
	
	int main( void ){
		
		Fixed		a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;
		
		std::cout << Fixed::max( a, b ) << std::endl;
		
		return 0;
	}	

#else

	std::string boolStr(bool boolean)
	{
		return boolean ? "true" : "false";
	}

	int	main( void )
	{	
		Fixed fractionalMin;
		fractionalMin.setRawBits(1);
		fractionalMin.printRawBits();
	
		Fixed fractionalMax;
		fractionalMax.setRawBits(255);
		fractionalMax.printRawBits();
		
		std::cout << "\n-----------------\n" << std::endl; 
		
		Fixed a(4);
		Fixed b(5);
		std::cout << "a = " << a << std::endl; 
		std::cout << "b = " << b << std::endl; 
		
		std::cout << std::endl; 
		
		std::cout << a << " < " << b << " = " << boolStr(a < b) << std::endl;
		std::cout << a << " > " << b << " = " << boolStr(a > b) << std::endl;
		std::cout << a << " <= " << b << " = " << boolStr(a <= b) << std::endl;
		std::cout << a << " >= " << b << " = " << boolStr(a >= b) << std::endl;
		std::cout << a << " == " << b << " = " << boolStr(a == b) << std::endl;
		std::cout << a << " != " << b << " = " << boolStr(a != b) << std::endl;
		
		std::cout << std::endl; 
	
		std::cout << a << " + " << b << " = " << a + b << std::endl; 
		std::cout << a << " - " << b << " = " << a - b << std::endl; 
		std::cout << b << " - " << a << " = " << b - a << std::endl; 
		std::cout << a << " * " << b << " = " << a * b << std::endl; 
		std::cout << a << " / " << b << " = " << a / b << std::endl; 
	
		std::cout << std::endl; 
	
		std::cout << "++" << ++a << std::endl; 
		std::cout << "  ↳ " << a << std::endl; 
		std::cout << "--" << --b << std::endl; 
		std::cout << "  ↳ " << b << std::endl; 
		
		std::cout << a-- << "--" << std::endl; 
		std::cout << "  ↳ " << a << std::endl; 
		std::cout << b++ << "++" << std::endl; 
		std::cout << "  ↳ " << b << std::endl; 

		std::cout << std::endl;

		std::cout << "min: " << Fixed::min(a, b) << std::endl;
		std::cout << "max: " << Fixed::max(a, b) << std::endl;
		
		return 0;
	}

#endif
