/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:01:51 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/02 09:23:49 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# if COLOR
#  define CLR_RESET			"\e[0m"
#  define CLR_GRNBOLD		"\e[1;32m"
#  define CLR_DIMGRNBOLD	"\e[2;1;32m"
#  define CLR_REDBOLD		"\e[1;31m"
#  define CLR_DIMRED		"\e[2;31m"
# else
#  define COLOR 0
#  define CLR_RESET			""
#  define CLR_GRNBOLD		""
#  define CLR_DIMGRNBOLD	""
#  define CLR_REDBOLD		""
#  define CLR_DIMRED		""
# endif

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void set_name(std::string name);
		void announce(void);

	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
