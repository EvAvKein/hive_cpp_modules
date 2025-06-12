/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:45 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/12 16:46:40 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#if true

	/*
	The code below is provided by the instructions

	I'm aware that it causes a duplicate inclusion of <iostream>,
	but including that inclusion means I comply with the instructions to the letter.
	Good thing <iostream> has a header guard :)
	*/

	#include <iostream>
	
	int main( void )
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		
		a = Fixed( 1234.4321f );
		
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		
		return 0;
	}

#else

	int	main( void )
	{	
		{
			Fixed fractionalMin;
			fractionalMin.setRawBits(1);
			fractionalMin.printRawBits();
		}
		{
			Fixed fractionalMax;
			fractionalMax.setRawBits(255);
			fractionalMax.printRawBits();
		}
		return 0;
	}

#endif
