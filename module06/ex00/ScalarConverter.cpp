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

void ScalarConverter::convert(std::string_view str)
{
	std::string convertStr(str);

	literalType type = parseType(convertStr);

	switch (type)
	{
	case INVALID:
	{
	}
	case CHAR:
	{
	}
	case INT:
	{
	}
	case FLT:
	{
	}
	case DBL:
	{
	}
	default:
	{
		std::cout << "Impossible condition" << std::endl;
	}
	}

	printStrToChar(str);
	printStrToInt(str);
	printStrToFloat(str);
	printStrToDouble(str);
}

ScalarConverter::literalType ScalarConverter::parseType(std::string &str)
{
	size_t strlen = str.length();

	if (strlen == 0)
		return INVALID;

	if (str == "+inf" || str == "-inf" || str == "nan")
		return DBL;

	if (str == "+inff" || str == "-inff" || str == "nanf")
		return FLT;

	if (str.find_first_not_of("0123456789.f-+") != str.npos)
		return INVALID;

	if ((strlen == 1 && !std::isdigit(str[0])) || (strlen == 3 && str[0] == '\'' && str[2] == '\''))
		return CHAR;

	size_t signIndex = str.find_last_of('-+');
	if (signIndex != str.npos && signIndex != 0)
		return INVALID;

	size_t fCharIndex = str.find_first_of('f');
	if (fCharIndex != str.npos && fCharIndex != strlen - 1)
		return INVALID;

	size_t decimalIndex = str.find_first_of('.');
	if (decimalIndex != str.npos && decimalIndex != str.find_last_of('.'))
		return INVALID;

	if (decimalIndex == str.npos && fCharIndex != str.npos)
		return INVALID;

	bool hasWholeDigit = false;
	bool hasFractionalDigit = false;
	for (size_t i = 0; i < strlen; i++)
	{
		if (std::isdigit(str[i]))
		{
			if (i < decimalIndex)
				hasWholeDigit = true;
			else
				hasFractionalDigit = true;
		}
	}

	if (!hasWholeDigit && !hasFractionalDigit)
		return INVALID;

	if (!decimalIndex && fCharIndex == str.npos)
		return INT;

	if (fCharIndex != str.npos)
		return FLT;

	return DBL;
}

void ScalarConverter::printStrToChar(std::string_view str)
{
	char c = *static_cast<char *>((char *)str.data());

	std::cout << "char: " << c << std::endl;
}

void ScalarConverter::printStrToInt(std::string_view str)
{
	(void)str;
}

void ScalarConverter::printStrToFloat(std::string_view str)
{
	(void)str;
}

void ScalarConverter::printStrToDouble(std::string_view str)
{
	(void)str;
}
