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
				std::cout << "Bad :)" << std::endl;
				break;
		}
		case CHAR:
		{
				convertFromChar(convertStr);
				break;
		}
		case INT:
		{
				convertFromInt(convertStr);
				break;
		}
		case FLT:
		{
				convertFromFloat(convertStr);
				break;
		}
		case DBL:
		{
				convertFromDouble(convertStr);
				break;
		}
		default:
		{
			std::cout << "Impossible condition" << std::endl;
		}
	}
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

	if ( (strlen == 1 && !std::isdigit(str[0]))
		|| (strlen == 3 && str[0] == '\'' && str[2] == '\'') )
	{
		if (str[0] == '\'' && str[2] == '\'')
			str.erase(2, 1).erase(0, 1);
		return CHAR;
	}

	if (str.find_first_not_of("0123456789.f-+") != str.npos)
		return INVALID;

	size_t signIndex = str.find_last_of("-+");
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

	if (decimalIndex == str.npos && fCharIndex == str.npos)
		return INT;

	if (fCharIndex != str.npos)
		return FLT;

	return DBL;
}

void ScalarConverter::convertFromChar(std::string& str)
{
	printChar(str[0]);
	std::cout << "\n";

	int integer = static_cast<int>(str[0]);
	printInt(integer);
	std::cout << "\n";

	float flt = static_cast<float>(str[0]);
	printFloat(flt);
	std::cout << ".0f\n";

	double dbl = static_cast<double>(str[0]);
	printDouble(dbl);
	std::cout << ".0\n";

	std::cout << std::flush;
}

void ScalarConverter::convertFromInt(std::string& str)
{
	// std::cout << "NOT YET IMPLEMENTED" << std::endl;
	try
	{
		int integer = std::stoi(str);
		char chr = static_cast<char>(integer);

		printChar(chr);
		std::cout << '\n';

		printInt(integer);
		std::cout << '\n';

		float flt = static_cast<float>(integer);
		printFloat(flt);
		std::cout << ".0f\n"; 

		double dbl = static_cast<double>(integer);
		printDouble(dbl);
		std::cout << ".0\n";

		std::cout << std::flush;
	}
	catch (...)
	{
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: impossible\n"
			<< "double: impossible\n"
		<< std::flush;
	};

	(void) str;
}

void ScalarConverter::convertFromFloat(std::string& str)
{
	std::cout << "FLOAT CONVERSION NOT YET IMPLEMENTED" << std::endl;
	(void) str;
}

void ScalarConverter::convertFromDouble(std::string& str)
{
	std::cout << "DOUBLE CONVERSION NOT YET IMPLEMENTED" << std::endl;
	(void) str;
}

void ScalarConverter::printChar(char& chr)
{
	if (chr < 0 || chr > 127)
		std::cout << "char: impossible";
	else if (!std::isprint(chr))
		std::cout << "char: Non displayable";
	else
		std::cout << "char: '" << chr << "'";
}

void ScalarConverter::printInt(int& integer)
{
	std::cout << "int: " << integer;
}

void ScalarConverter::printFloat(float& flt)
{
	std::cout << "float: " << flt;
}

void ScalarConverter::printDouble(double& dbl)
{
	std::cout << "double: " << dbl;
}

