/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_processing.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:14:47 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 21:35:50 by ekeinan          ###   ########.fr       */
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
			std::cerr << CLR_REDBOLD "Phone number may only have a plus as the first character" CLR_RESET << std::endl;
			return nullptr;
		}
		if ((*str)[1] == '0')
		{
			std::cerr << CLR_REDBOLD "Phone number's first digit after plus can't be zero" CLR_RESET << std::endl;
			return nullptr;
		}
	}

	u_int8_t	min_digits = 10;
	u_int8_t	max_digits = min_digits + 2;
	num = &num[has_plus];
	i = 0;
	while (num[i])
	{
		if (i >= max_digits)
		{
			std::cerr << CLR_REDBOLD "Phone number cannot be longer than " << (int)max_digits << " digits" CLR_RESET << std::endl;
			return nullptr;
		}
		if (!std::isdigit(num[i++]))
		{
			std::cerr <<
				CLR_REDBOLD "Phone number can only contain digits\n" CLR_RESET
				CLR_DIM "(optionally with a leading '+' if including country code)" CLR_RESET
			<< std::endl;
			return nullptr;
		}
	}
	if (i < min_digits)
	{
		std::cerr << CLR_REDBOLD "Phone number cannot be less than " << (int)min_digits << " digits" CLR_RESET << std::endl;
		return nullptr;
	}
	return (str);
}

std::string	*not_empty(std::string *str)
{
	if (str->length() == 0)
	{
		std::cerr << CLR_REDBOLD "Field cannot be empty" CLR_RESET << std::endl;
		return nullptr;
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
		if (!validation[i++](input))
			return false;
	}
	return true;
}

std::string	receive_field(std::string &prompt, str_parser* validation)
{
	std::string	field;

	while (1)
	{
		std::cout << CLR_YLLWBOLD << prompt << CLR_RESET << std::endl;
		std::getline(std::cin, field);
		if (std::cin.eof())
		{
			if (field.size())
				std::cout << std::endl;
			return "";
		}
		if (validate(&field, validation))
			break;
	}
	return field;
}