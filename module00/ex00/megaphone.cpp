/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:36:30 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/23 13:29:20 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> // already included in iostream, but isn't included on older systems/compilers

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return EXIT_FAILURE;
	}

	std::string str;	
	size_t		strlen;	
	for (int i_str = 1; i_str < argc; i_str++)
	{
		str = argv[i_str];
		strlen = str.length();
		for (size_t i_chr = 0; i_chr < strlen; i_chr++)
			std::cout << (char)std::toupper(str[i_chr]);
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
