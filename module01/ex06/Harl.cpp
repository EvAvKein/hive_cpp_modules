/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:41:31 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/26 12:50:42 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{	
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	complaint funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	u_int8_t i = 0;

	while (i < 4 && names[i] != level)
		i++;
	if (i < 4)
		std::cout << "[ " << names[i] << " ]" << std::endl;
	switch (i)
	{
		case 0:
			(this->*funcs[i++])();
		case 1:
			(this->*funcs[i++])();
		case 2:
			(this->*funcs[i++])();
		case 3:
			(this->*funcs[i++])();
			break;
		default:
			std::cout <<
				CLR_CYNBOLD "Sorry, \"" CLR_RESET <<
				level <<
				CLR_CYNBOLD "\" is not a valid complaint :P" CLR_RESET
			<< std::endl;
	}
}	

void Harl::debug(void)
{
	std::cout << CLR_PRPBOLD
		"Debugging is tedious :("
	CLR_RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << CLR_BLUBOLD
		"Info? Why do we need more of that? ;_;"
	CLR_BLUBOLD << std::endl;
}

void Harl::warning(void)
{
	std::cout << CLR_YLWBOLD
		"Warnings prevent me from doing what I wanna D:"
	CLR_RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << CLR_REDBOLD
		"Errors mean the thing isn't working :c"
	CLR_RESET << std::endl;
}
