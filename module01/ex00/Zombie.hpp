/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:01:51 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 15:06:00 by ekeinan          ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		void announce(void);

	private:
		std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
