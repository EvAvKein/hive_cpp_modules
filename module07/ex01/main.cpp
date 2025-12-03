/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/12/03 15:42:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(std::string_view& string) {
	std::cout << string << std::endl;
}

int main(void) {
	void				(*nullFunc)(int&) = 0;
	std::string_view	*nullArr = 0;

	int		numbers[] = {1,2,3};

	iter(numbers, 999, nullFunc);
	iter(nullArr, 999, print);

	iter(numbers, 3, (void (*)(int&)) [](int& num){
		std::cout << "I have the number " << num << std::endl;
	});

	iter<void (*)(std::string_view&)>((void (*[])(std::string_view& str)) {print}, 1,
		(void (*)(void (*)(std::string_view&))) ( void (*&)(std::string_view&) ) {
			// func("string");
		}
	);
}
