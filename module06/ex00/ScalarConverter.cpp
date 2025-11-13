/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/13 16:34:57 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string_view str)
{
	if (printLiteral(str))
		return ;

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

bool ScalarConverter::printLiteral(std::string_view& str)
{
	// TODO
	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;

	if (str == "+inff" || str == "-inff" || str == "nanf")
		return true;

	return false;
}

ScalarConverter::literalType ScalarConverter::parseType(std::string &str)
{
	size_t strlen = str.length();

	if (strlen == 0)
		return INVALID;

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

	int integer = static_cast<int>(str[0]);
	printInt(integer);

	float flt = static_cast<float>(str[0]);
	printFloat(flt);

	double dbl = static_cast<double>(str[0]);
	printDouble(dbl);

	std::cout << std::flush;
}

void ScalarConverter::convertFromInt(std::string& str)
{
	try
	{
		int integer = std::stoi(str);
		char chr = static_cast<char>(integer);

		if (integer > float(std::numeric_limits<char>::max())
			|| integer < float(std::numeric_limits<char>::min()))
			std::cout << "char:	impossible\n";
		else
			printChar(chr);

		printInt(integer);

		float flt = static_cast<float>(integer);
		printFloat(flt);

		double dbl = static_cast<double>(integer);
		printDouble(dbl);

		std::cout << std::flush;
	}
	catch (...)
	{
		std::cout
			<< "char:	impossible\n"
			<< "int:	impossible\n"
			<< "float:	impossible\n"
			<< "double:	impossible\n"
		<< std::flush;
	};
}

void ScalarConverter::convertFromFloat(std::string& str)
{
	try
	{
		float flt = std::strtof(str.c_str(), nullptr);

		if (flt == HUGE_VALF)
			throw std::exception();

		int integer = static_cast<int>(flt);
		char chr = static_cast<char>(integer);

		if (flt > float(std::numeric_limits<char>::max())
			|| flt < float(std::numeric_limits<char>::min()))
			std::cout << "char:	impossible\n";
		else
			printChar(chr);
			
		if (flt > float(std::numeric_limits<int>::max())
			|| flt < float(std::numeric_limits<int>::min()))
			std::cout << "int:	impossible\n";
		else
			printInt(integer);

		printFloat(flt);

		double dbl = static_cast<double>(flt);
		printDouble(dbl);

		std::cout << std::flush;
	}
	catch (...)
	{
		std::cout
			<< "char:	impossible\n"
			<< "int:	impossible\n"
			<< "float:	impossible\n"
			<< "double:	impossible\n"
		<< std::flush;
	};
}
// TEST ./convert 2147483648.f
//      (and slightly lower values, and same with negatives)

void ScalarConverter::convertFromDouble(std::string& str)
{
	try
	{
		double dbl = std::strtod(str.c_str(), nullptr);

		if (dbl == HUGE_VALL)
			throw std::exception();

		int integer = static_cast<int>(dbl);
		char chr = static_cast<char>(integer);

		if (dbl > float(std::numeric_limits<char>::max())
			|| dbl < float(std::numeric_limits<char>::min()))
			std::cout << "char:	impossible\n";
		else
			printChar(chr);
			
		float flt = static_cast<float>(dbl);
		if (flt > float(std::numeric_limits<int>::max())
			|| flt < float(std::numeric_limits<int>::min()))
			std::cout << "int:	impossible\n";
		else
			printInt(integer);

		printFloat(flt);

		printDouble(dbl);

		std::cout << std::flush;
	}
	catch (...)
	{
		std::cout
			<< "char:	impossible\n"
			<< "int:	impossible\n"
			<< "float:	impossible\n"
			<< "double:	impossible\n"
		<< std::flush;
	};
}

void ScalarConverter::printChar(char& chr)
{
	if (chr < 0 || chr > 127)
		std::cout << "char:	impossible\n";
	else if (!std::isprint(chr))
		std::cout << "char:	Non displayable\n";
	else
		std::cout << "char:	'" << chr << "'\n";
}

void ScalarConverter::printInt(int& integer)
{
	std::cout << "int:	" << integer << "\n";
}

void ScalarConverter::printFloat(float& flt)
{
	std::cout << "float:	" << std::fixed << std::setprecision(1) << flt << "f\n";	
}

void ScalarConverter::printDouble(double& dbl)
{
	std::cout << "double:	" << std::fixed << std::setprecision(1) << dbl << "\n";
}
