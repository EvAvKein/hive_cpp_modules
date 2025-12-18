/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/12/03 16:22:28 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
	try {
		Array<int> intArr;
		std::cout << "Int array of size " << intArr.size() << std::endl;
		try {
			intArr[1];
		} catch (std::out_of_range& e) {
			std::cout << "Exception with `intArr[1]`: " << e.what() << std::endl;
		}
	} catch (std::bad_alloc &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Array<char> charArr(5);
		charArr[0] = 'H';
		charArr[1] = 'e';
		charArr[2] = 'l';
		charArr[3] = 'l';
		charArr[4] = 'o';
		std::cout << "Char Array created, and assigned these characters (indexed):";
		for (unsigned int i = 0; i < charArr.size(); i++)
			std::cout << " \'" << charArr[i] << '\'';
		std::cout << std::endl;

		Array<char> charArrCopy(charArr);
		std::cout << "Char Array copy created and has these characters (indexed):";
		for (unsigned int i = 0; i < charArrCopy.size(); i++)
			std::cout << " \'" << charArrCopy[i] << '\'';
		std::cout << std::endl;
	} catch (std::bad_alloc &e) {
		std::cout << e.what() << std::endl;
	}
}
