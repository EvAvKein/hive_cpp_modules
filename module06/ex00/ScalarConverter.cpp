/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/03 13:45:09 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string_view str)
{
	literalType type = parseType(str);

	switch (type)
	{
		case INVALID: {

		}
		case CHAR: {

		}
		case INT: {

		}
		case FLT: {

		}
		case DBL: {

		}
		default: {
			std::cout << "Impossible condition" << std::endl;
		}

	}

	printStrToChar(str);
	printStrToInt(str);
	printStrToFloat(str);
	printStrToDouble(str);
}

ScalarConverter::literalType	ScalarConverter::parseType(std::string_view str)
{
	size_t strlen = str.length();


	if (strlen == 0)
		return INVALID;

	if ( (strlen == 1 && !std::isdigit(str[0]) )
		|| (strlen == 3 && str[0] == '\'' && str[2] == '\'') )
		return CHAR;

	if (str.find_first_not_of("0123456789.f-+") != str.npos)
		return INVALID;

	auto c = str.find_first_of('.');
	if (true) // TODO conditions for decimal dup/misplacement :P
		;

	if (str.find_first_of(".f") == str.npos)
		  return INT;

	else if ((
				str.find_last_of('f') != str.npos
				&& (str[strlen - 1] != 'f'
					|| str.find_first_of('f') != str.find_last_of('f'))
			 ))
		;
	
}

void	ScalarConverter::printStrToChar(std::string_view str)
{
	char c = *static_cast<char*>((char*)str.data());

	std::cout << "char: " << c << std::endl;
}

void	ScalarConverter::printStrToInt(std::string_view str)
{
	(void) str;
}

void	ScalarConverter::printStrToFloat(std::string_view str)
{
	(void) str;
}

void	ScalarConverter::printStrToDouble(std::string_view str)
{
	(void) str;
}

