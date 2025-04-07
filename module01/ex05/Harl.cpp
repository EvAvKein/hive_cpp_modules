/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:41:31 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 10:58:10 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl arrived!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl left!" << std::endl;
}

void Harl::complain(std::string level)
{	
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	complaint funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (names[i] == level)
			return (this->*funcs[i])();
	}
	
	std::cerr << "Sorry, \"" << level << "\" is not a valid complaint :P" << std::endl;
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
	std::cout << "Errors mean the thingy isn't working :c" << std::endl;
}
