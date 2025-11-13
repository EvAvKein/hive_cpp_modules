/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/13 15:50:12 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string_view>
#include <iostream>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
public:
	ScalarConverter(void) = delete;
	ScalarConverter(ScalarConverter const &copied) = delete;
	ScalarConverter &operator=(ScalarConverter const &assigned) = delete;
	~ScalarConverter(void) = delete;

	static void convert(std::string_view str);

private:
	enum literalType
	{
		INVALID,
		CHAR,
		INT,
		FLT,
		DBL,
	};

	static bool			printLiteral(std::string_view& str);
	static literalType	parseType(std::string& str);

	static void printChar(char& chr);
	static void printInt(int& integer);
	static void printFloat(float& flt);
	static void printDouble(double& dbl);

	static void convertFromChar(std::string& str);
	static void convertFromInt(std::string& str);
	static void convertFromFloat(std::string& str);
	static void convertFromDouble(std::string& str);
};

#endif
