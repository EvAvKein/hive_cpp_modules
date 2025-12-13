/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:42 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <limits>
#include <vector>

int main(void)
{
	try
	{
		std::vector<int> ints = {1, -2, std::numeric_limits<int>::max()};
		auto searched = easyfind(ints, 0);
		std::cout << "Easyfind found: 0" << (searched.has_value() ? "true" : "false") << std::endl;
		searched = easyfind(ints, -2);
		std::cout << "Easyfind found: " << *searched.value() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
