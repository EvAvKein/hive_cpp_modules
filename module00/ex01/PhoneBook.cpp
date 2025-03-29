/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:48:03 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/29 17:50:51y ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contacts(), oldest(0), filled(0)
{}

bool PhoneBook::add_contact()
{
	str_parser generic_str_vali[3] = {trim, not_empty, NULL};
	str_parser phonenum_vali[4] = {trim, not_empty, vaguely_phonenum, NULL};
	
	t_step steps[5] = {
		{"First name?", generic_str_vali},
		{"Last name?", generic_str_vali},
		{"Nickname?", generic_str_vali},
		{"Phone number?", phonenum_vali},
		{"Darkest secret?", generic_str_vali}
	};	
	std::string buffer[5];
	for (int i = 0; i < 5; i++)
	{
		buffer[i] = receive_field(steps[i].prompt, steps[i].validation_funcs);
		if (buffer[i].empty())
		{
			std::cout << "Cancelling contact creation..." << std::endl;
			return false;
		}
	}
	u_int8_t *i = filled == 8 ? &oldest : &filled;
	contacts[*i] = Contact(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
	std::cout << CLR_GREENBOLD "Contact " << (int)((*i)++) << " created!" CLR_RESET << std::endl;
	if (i == &oldest)
		*i %= 8;
	return true;
}

static std::string trunc_for_column(std::string text)
{
	if (text.length() > 10)
		return text.substr(0, 9).append(".");
	return text;
}

void PhoneBook::print_contacts()
{
	std::cout << std::string(45, '-') << std::endl;
	std::cout <<
		"|" << std::setw(10) << CLR_YLLWBGBOLD "     INDEX" CLR_RESET
		"|" << std::setw(10) << CLR_YLLWBGBOLD "FIRST NAME" CLR_RESET
		"|" << std::setw(10) << CLR_YLLWBGBOLD " LAST NAME" CLR_RESET
		"|" << std::setw(10) << CLR_YLLWBGBOLD "  NICKNAME" CLR_RESET
		"|"
	<< std::endl;
	std::cout << std::string(45, '-') << std::endl;	
	
	u_int8_t i = 0;
	if (filled)
	{
		while (i < filled)
		{
			std::cout <<
				"|" << std::setw(10) << (int)i <<
				"|" << std::setw(10) << trunc_for_column(contacts[i].get_first_name()) <<
				"|" << std::setw(10) << trunc_for_column(contacts[i].get_last_name()) <<
				"|" << std::setw(10) << trunc_for_column(contacts[i].get_nickname()) <<
				"|"
			<< std::endl;
			i++;
		}
	}
	else
	{
		std::cout <<
			"|  NO CONTACT ADDED, USE THE \"ADD\" COMMAND! |"
		<< std::endl;
	}

	std::cout << std::string(45, '-') << std::endl;
}

void PhoneBook::print_contact_info(u_int8_t index)
{
	Contact contact = contacts[index];

	std::cout << CLR_BACKGROUND "First name" CLR_RESET << std::endl;
	std::cout << contact.get_first_name() << std::endl;
	
	std::cout << CLR_BACKGROUND "Last name" CLR_RESET << std::endl;
	std::cout << contact.get_last_name() << std::endl;
	
	std::cout << CLR_BACKGROUND "Nickname" CLR_RESET << std::endl;
	std::cout << contact.get_nickname() << std::endl;
	
	std::cout << CLR_BACKGROUND "Phone number" CLR_RESET << std::endl;
	std::cout << contact.get_phone_number() << std::endl;
	
	std::cout << CLR_BACKGROUND "Darkest secret" CLR_RESET << std::endl;
	std::cout << contact.get_darkest_secret() << std::endl;
}

void PhoneBook::search_contacts()
{
	print_contacts();

	while (1)
	{
		std::string prompt = "Input a contact index to display info";
		std::string index_input = receive_field(prompt, (str_parser[2]){trim, NULL});
		if (index_input.length() != 1 || index_input[0] > '9' || index_input[0] < '0')
		{
			std::cerr << CLR_REDBOLD "Index can only be a single digit" CLR_RESET << std::endl;
			break;
		}
		u_int8_t index = index_input[0] - '0';
		if (index + 1 > filled)
		{
			std::cerr << CLR_REDBOLD "A contact with this index doesn't exist" CLR_RESET << std::endl;
			break;
		}
		print_contact_info(index);
		std::cout << std::string(45, '-') << std::endl;
		return ;	
	}	
	std::cout <<
		CLR_DIMBOLD "Quitting index query, rerun " CLR_RESET
		CLR_GREENBOLD "SEARCH" CLR_RESET
		CLR_DIMBOLD " to try again" CLR_RESET
	<< std::endl;
}
