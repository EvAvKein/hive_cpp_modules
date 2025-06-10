/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:45 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/03 08:54:45 by ekeinan          ###   ########.fr       */
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

	int	main( void ) {
		Fixed a;
		Fixed b( a );
		Fixed c;
		
		c = b;
		
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		
		return 0;
	}

#else

	int	main( void ) {
		Fixed a;
		
		std::cout 
			<< "-----" <<  std::endl
			<< "a: " << std::endl
			<< a.getRawBits() << std::endl
			<< "-----" <<  std::endl;

		a.setRawBits(404);

		Fixed *b;

		b = new Fixed(a);
		
		std::cout
			<< "-----" <<  std::endl
 			<< "b: " << std::endl
			<< b->getRawBits() << std::endl
			<< "-----" <<  std::endl;

		delete b;

		Fixed *c;

		c = new Fixed();

		c->setRawBits(985);

		*c = Fixed(*c);
				
		std::cout
			<< "-----" <<  std::endl
			<< "c: " << std::endl
			<< c->getRawBits() << std::endl
			<< "-----" <<  std::endl;

		delete c;

		return 0;
	}

#endif