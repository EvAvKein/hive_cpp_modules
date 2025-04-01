/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:38:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 12:00:03 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include "field_processing.hpp"

typedef struct s_step
{
	std::string	prompt;
	str_parser	*validation_funcs;
}				t_step;

class PhoneBook
{
	private:
		Contact		contacts[8];
		u_int8_t	oldest;
		u_int8_t	filled;
		void		print_contacts();
		void		print_contact_info(u_int8_t index);

	public:
		PhoneBook();
		bool	add_contact();
		void	search_contacts();
};

#endif
