/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:38:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/25 10:37:15 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include "field_processing.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];
		u_int8_t	oldest;
		u_int8_t	filled;

	public:
		PhoneBook();
		void	add_contact();
		void	search_contacts();
};

#endif
