/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:54:51 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/25 18:16:54 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact():
	first_name(""), last_name(""),
	nickname(""), phone_number(""),
	darkest_secret("")
{}
Contact::Contact(
	std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number,
	std::string darkest_secret):
	first_name(first_name), last_name(last_name),
	nickname(nickname), phone_number(phone_number),
	darkest_secret(darkest_secret)
{}
std::string Contact::get_first_name() {return first_name;}
std::string Contact::get_last_name() {return last_name;}
std::string Contact::get_nickname() {return nickname;}
std::string Contact::get_phone_number() {return phone_number;}
std::string Contact::get_darkest_secret() {return darkest_secret;}
