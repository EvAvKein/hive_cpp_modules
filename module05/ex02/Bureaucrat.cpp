/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/25 13:23:55 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): name("Jack"), grade(150)
{
	std::cout <<
		"Some unimportant bureaucrat (grade " << grade << ") got hired"
		", we'll just call them " << name << "."
	<< std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade): name(name), grade(grade)
{
	if (grade < 1)
	{
		std::cout <<
			"Cannot hire bureaucrat " << name <<
			", grade " << grade << " is too high."
		<< std::endl;
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		std::cout <<
			"Cannot hire bureaucrat " << name <<
			", grade " << grade << " is too low."
		<< std::endl;
		throw GradeTooLowException();
	}
	std::cout <<
		"A bureaucrat named " << name <<
		" (grade " << grade  << ") got hired."
	<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copied): name(copied.name), grade(copied.grade)
{
	std::cout <<
		"Corporate is hiring a bureaucrat who's exactly like " << name <<
		" (including grade " << grade << ")" <<
		". Corporate really likes " << name << " apparently."
	<< std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << 
		"A bureaucrat named " << name <<
		" (grade " << grade  << ") got fired."
	<< std::endl;
}

std::string const& Bureaucrat::getName(void) const
{
	return name;
}

int const& Bureaucrat::getGrade(void) const
{
	return grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void): std::out_of_range("Grade is too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void): std::out_of_range("Grade is too low")
{
}

void	Bureaucrat::incrementGrade(void)
{
	if (grade <= 1)
		throw GradeTooHighException();
	std::cout <<
		"Corporate promoted bureaucrat " << name <<
		" to grade " << --grade << ". Congratulations."
	<< std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	if (grade >= 150)
		throw GradeTooLowException();
	std::cout <<
		"Corporate demoted bureaucrat " << name <<
		" to grade " << ++grade << ". Commiserations."
	<< std::endl;
}

void	Bureaucrat::signForm(AForm& form) const
{
	form.beSigned(*this);
	// ^ Outcome printouts are inside here
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	form.execute(*this);
	// ^ Failure printouts are inside here
	std::cout << 
		getName() << " executed " << form.getName() << "."
	<< std::endl;

}

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat &bureaucrat)
{
	ostream <<
		bureaucrat.getName() <<
		", bureaucrat grade " << bureaucrat.getGrade() << "."
	<< std::endl;
	return ostream;
}
