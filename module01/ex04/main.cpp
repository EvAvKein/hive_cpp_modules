/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:07:11 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/03 08:53:18by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

typedef	struct		s_data
{
	std::ifstream	infile;
	std::string		s1;
	std::string		s2;
	size_t			s1_len;
	std::ofstream	outfile;
}					t_data;

static inline void prep_and_validation(int &argc, char **argv, t_data &data)
{
	if (argc != 4)
		throw std::string("SIFL needs exactly 3 arguments: file, string to replace, and string that'll be the replacement");

	data.s1 = argv[2];
	data.s1_len = data.s1.length();
	if (!data.s1_len)
		throw std::string("SIFL's string to replace (second arg) must not be empty");
	
	data.s2 = argv[3];
	
	try {
		data.infile = std::ifstream(argv[1]);
	} catch (std::string error) {
		throw std::move(error);
	}

	try {
		data.outfile = std::ofstream(std::string(argv[1]).append(".replace"));
	} catch (std::string error) {
		data.infile.close();
		throw std::move(error);
	}
}
int main(int argc, char** argv)
{
	t_data	data;

	try
	{
		prep_and_validation(argc, argv, data);
	}
	catch (std::string& error)
	{
		std::cerr << error << std::endl;
		return EXIT_FAILURE;
	}
	
	std::string		line;
	size_t			match_i;
	
	while (getline(data.infile, line, '\n'))
	{
		match_i = line.find(data.s1, 0);

		if (match_i == std::string::npos)
			data.outfile << line;
		else
		{
			while (match_i != std::string::npos)
			{
				data.outfile << line.substr(0, match_i).append(data.s2);
				line.erase(0, match_i + data.s1_len);
				match_i = line.find(data.s1, 0);
			}
			data.outfile << line;
		}

		if (!data.infile.eof())
			data.outfile << std::endl;
	}
	
	data.infile.close();
	data.outfile.close();

	return EXIT_SUCCESS;
}
