/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string_view>
#include <iostream>

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

	static literalType parseType(std::string &str);

	static void printStrToChar(std::string_view str);
	static void printStrToInt(std::string_view str);
	static void printStrToFloat(std::string_view str);
	static void printStrToDouble(std::string_view str);
};

#endif
