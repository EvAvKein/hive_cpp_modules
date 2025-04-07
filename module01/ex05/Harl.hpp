/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:41:25 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 09:59:40y ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# if COLOR
#  define CLR_RESET			"\e[0m"
#  define CLR_PRPBOLD		"\e[1;35m"
#  define CLR_BLUBOLD		"\e[1;34m"
#  define CLR_YLWBOLD		"\e[1;33m"
#  define CLR_REDBOLD		"\e[1;31m"
#  define CLR_CYNBOLD		"\e[1;36m"
# else
#  define COLOR 0
#  define CLR_RESET			""
#  define CLR_PRPBOLD		""
#  define CLR_BLUBOLD		""
#  define CLR_YLWBOLD		""
#  define CLR_REDBOLD		""
#  define CLR_CYNBOLD		""
# endif

class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

typedef void (Harl::*complaint)(void);

#endif
