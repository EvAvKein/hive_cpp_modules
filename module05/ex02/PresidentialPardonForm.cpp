/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/18 11:47:45 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target):
	AForm("Presidential Pardon", 25, 5)
{
	this->target = target;
	std::cout <<
		"We got some " << getName() << " form, targeting \"" <<  target << "\"."
	<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copied):
	AForm(copied)
{
	target = copied.target;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	throwIfCantExecForm(executor);
	std::cout <<
		target << " has been pardoned by Zaphod Beeblebrox."
	<< std::endl;
};
