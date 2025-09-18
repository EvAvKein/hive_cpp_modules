/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/17 12:04:18 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target):
	AForm("Robotomy Request", 72, 45)
{
	this->target = target;
	std::cout <<
		"We got some " << getName() << " form, targeting \"" <<  target << "\"."
	<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copied):
	AForm(copied)
{
	target = copied.target;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	throwIfCantExecForm(executor);
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution<std::mt19937::result_type> chance(1,100);

	if (chance(rng) > 50)
		std::cout << target << " has been robotomized." << std::endl;
	else
		std::cout << target << " robotomy has failed." << std::endl;
};
