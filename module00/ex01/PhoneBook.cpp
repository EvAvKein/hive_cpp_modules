/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:48:03 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/26 09:58:22 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contacts(), oldest(0), filled(0)
{}

void PhoneBook::add_contact()
{
	str_parser generic_str_vali[3] = {trim, not_empty, NULL};
	str_parser phonenum_vali[4] = {trim, not_empty, vaguely_phonenum, NULL};
	u_int8_t &i = filled == 8 ? oldest : filled;

	// Created buffer because calling the funcs at constructor args executes them in reverse order
	std::string buffer[5] = {
		receive_field("First name?", generic_str_vali),
		receive_field("Last name?", generic_str_vali),
		receive_field("Nickname?", generic_str_vali),
		receive_field("Phone number?", phonenum_vali),
		receive_field("Darkest secret?", generic_str_vali)
	};
	contacts[i++] = Contact(
		buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]
	);
	std::cout << "Contact " << (int)(i - 1) << " created!" << std::endl;
}

static std::string trunc_for_column(std::string text)
{
	if (text.length() > 10)
		return text.substr(0, 9).append(".");
	return text;
}

void PhoneBook::search_contacts()
{
	std::cout << std::string(45, '-') << std::endl;
	std::cout
		<< "|" << std::setw(10) << "INDEX"
		<< "|" << std::setw(10) << "FIRST NAME"
		<< "|" << std::setw(10) << "LAST NAME"
		<< "|" << std::setw(10) << "NICKNAME"
	<< "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;	
	
	u_int8_t i = 0;
	if (filled)
	{
		while (i < filled)
		{
			std::cout
				<< "|" << std::setw(10) << (int)i
				<< "|" << std::setw(10) << trunc_for_column(contacts[i].get_first_name())
				<< "|" << std::setw(10) << trunc_for_column(contacts[i].get_last_name())
				<< "|" << std::setw(10) << trunc_for_column(contacts[i].get_nickname())
			<< "|" << std::endl;
			i++;
		}
	}
	else
	{
		std::cout
			<< "|" << std::setw(43) << " NO CONTACT ADDED, USE THE \"ADD\" COMMAND! "
		<< "|" << std::endl;
	}

	std::cout << std::string(45, '-') << std::endl;
}
