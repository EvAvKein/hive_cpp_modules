/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:45 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 19:23:15 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
