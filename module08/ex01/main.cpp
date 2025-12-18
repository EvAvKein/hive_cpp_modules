/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/12/18 11:51:43 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span intSpan(7);
	Span extraIntSpan(5);
	std::vector<int> array;

	intSpan.addNumber(std::numeric_limits<int>::min());
	intSpan.addNumber(0);
	intSpan.addNumber(std::numeric_limits<int>::max());

	std::cout << intSpan.shortestSpan() << '\n';
	std::cout << intSpan.longestSpan() << '\n';
	std::cout << std::endl;

	extraIntSpan.addNumber(-2);
	extraIntSpan.addNumber(3);
	extraIntSpan.addNumber(7);

	std::cout << extraIntSpan.shortestSpan() << '\n';
	std::cout << extraIntSpan.longestSpan() << '\n';
	std::cout << std::endl;

	for (int num = -1; num < 3; num++)
		array.push_back((num + 2) * 2);
	intSpan.addRange<std::vector<int>>(array.begin(), array.end());

	std::cout << intSpan.shortestSpan() << '\n';
	std::cout << intSpan.longestSpan() << '\n';
	std::cout << std::endl;

	try
	{
		intSpan.addRange<std::vector<int>>(array.begin(), array.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
