/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:00 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/13 10:02:07 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed &operator= (const Fixed& fixed);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int 					_value;
		static const u_int8_t	_bits = 8;
};
