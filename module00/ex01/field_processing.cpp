/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_processing.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:40:05 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/25 18:22:02ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field_processing.hpp"

std::string	*vaguely_phonenum(std::string *str)
{
	std::string num = *str;
	
	size_t	i = num.find_last_of('+');
	bool	has_plus = (i < std::string::npos);
	
	if (has_plus)
	{
		if (i)
		{
			std::cout << "Phone number may only have a plus as the first character" << std::endl;
			return NULL;
		}
		if ((*str)[1] == '0')
		{
			std::cout << "Phone number's first digit after plus can't be zero" << std::endl;
			return NULL;
		}
	}

	u_int8_t	min_digits = 10;
	u_int8_t	max_digits = min_digits + 2;
	num = &num[has_plus];
	i = 0;
	while (num[i])
	{
		if (i > max_digits)
		{
			std::cout << "Phone number cannot be longer than " << max_digits << " digits" << std::endl;
			return NULL;
		}
		if (!std::isdigit(num[i++]))
		{
			std::cout << "Phone number can only contain digits \e[2;37m(optionally with a leading '+' if including country code)\e[0;0m" << std::endl;
			return NULL;
		}
	}
	if (i < min_digits)
	{
		std::cout << "Phone number cannot be less than " << min_digits << " digits" << std::endl;
		return NULL;
	}
	return (str);
}

std::string	*not_empty(std::string *str)
{
	if (str->length() == 0)
	{
		std::cout << "Field cannot be empty" << std::endl;
		return NULL;
	}
	return str;
}

std::string	*trim(std::string *str)
{
	const std::string spaces = " \t\v\f\r\n";
	
	str->erase(str->find_last_not_of(spaces) + 1);
	str->erase(0, str->find_first_not_of(spaces));
	
	return (str);
}

static bool	validate(std::string *input, str_parser* validation)
{
	size_t		i = 0;
	
	while (validation[i])
	{
		if (validation[i++](input))
			continue;
		else			
			return false;
	}
	return true;
}

std::string	receive_field(std::string prompt, str_parser* validation)
{
	std::string	field = "";

	while (1)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, field);
		if (validate(&field, validation))
			break;
	}
	return field;
}