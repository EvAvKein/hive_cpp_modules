/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:00 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/11 12:43:07 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed &operator=(const Fixed& fixed);
		~Fixed();
	
		Fixed(const int value);
		Fixed(const float value);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits(void) const;
		int setRawBits(int const raw);

		int	getFixedIntMax(void) const;
		int toFractionalValue(void) const;
		void printRawBits(void);

	private:
		int 					_value;
		static const u_int8_t	_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
