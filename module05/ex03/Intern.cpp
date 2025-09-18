/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/18 11:45:59 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define FORM_COUNT 3

AForm*	Intern::makeForm(std::string const& formName, std::string const& formTarget) const
{
	const std::string	forms[FORM_COUNT] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	int					form_i = 0;
	AForm	*form = nullptr;

	while (form_i < FORM_COUNT)
	{
		if (formName == forms[form_i])
			break;
		form_i++;
	}

	if (form_i < FORM_COUNT)
		std::cout <<
			"Intern creates " << formName << "."
		<< std::endl;

	switch (form_i)
	{
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break;
		default: {
			std::cout <<
				"Intern received invalid form request: \"" << formTarget << "\""
			<< std::endl;
		}
	};

	return form;
}

#undef FORM_COUNT
