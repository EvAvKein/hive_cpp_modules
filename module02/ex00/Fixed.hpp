/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:00 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/02 09:59:20 by ekeinan          ###   ########.fr       */
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
		int setRawBits(int const raw);

	private:
		int 					value;
		static const u_int8_t	bits = 8;
};
