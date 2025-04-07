/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:41:31 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 10:58:06 by ekeinan          ###   ########.fr       */
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
	
	if (i == 4)
	{
		std::cerr << "Sorry, \"" << level << "\" is not a valid complaint :P" << std::endl;
		return ;
	} 

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
	}
}	

void Harl::debug(void)
{
	std::cout << "Debugging is tedious :(" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Info? Why do we need more of that? ;_;" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Warnings prevent me from doing what I wanna D:" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Errors mean the thing isn't working :c" << std::endl;
}
