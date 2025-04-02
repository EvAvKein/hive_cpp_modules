/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:07:11 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/02 08:51:42 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout <<
			"SIFL needs exactly 3 arguments: "
			"file, string to replace, and string that'll be the replacement"
		<< std::endl;
		return EXIT_FAILURE;
	}

	size_t	s1_len = std::string(argv[2]).length();
	if (!s1_len)
	
	size_t	s2_len = std::string(argv[3]).length();
	
	std::ifstream infile;
	try {
		infile = std::ifstream(argv[1]);
	} catch (std::exception error) {
		std::cout << "SIFL: " << error.what() << std::endl;
		return EXIT_FAILURE;
	}

	std::ofstream outfile;
	try {
		outfile = std::ofstream(std::string(argv[1]).append(".replace"));
	} catch (std::exception error) {
		infile.close();
		std::cout << "SIFL: " << error.what() << std::endl;
		return EXIT_FAILURE;
	}
	
	std::string	input;
	std::string match;
	while (getline(infile, input))
	{
		match = input.find();
		if (match == std::string::npos)
		{
			in
		}
	}

	infile.close();

	return EXIT_SUCCESS;
}
