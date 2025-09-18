/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/18 11:47:35 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target):
	AForm("Shrubbery Creation", 145, 137)
{
	this->target = target;
	std::cout <<
		"We got some " << getName() << " form, targeting \"" <<  target << "\"."
	<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copied):
	AForm(copied)
{
	target = copied.target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	throwIfCantExecForm(executor);

	std::ofstream file(target + "_shrubbery");
	if (!file.is_open())
		throw std::runtime_error("Shrubbery cannot be created.");
	file <<
		"               ,@@@@@@@,                 \n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.     \n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    \n"
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   \n"
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   \n"
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    \n"
		"   `&%\\ ` /%&'    |.|        \\ '|8'      \n"
		"       |o|        | |         | |        \n"
		"       |.|        | |         | |        \n"
		"_/\\_\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
};
