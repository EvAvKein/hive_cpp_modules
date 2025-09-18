/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/18 11:48:43 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):
	name("UnFORMulated"), grade_sign_req(150),
	grade_exec_req(150), is_signed(false)
{
	std::cout <<
		"We got some " << name << " form."
	<< std::endl;
}

Form::Form(std::string const& name, int grade_sign_req, int grade_exec_req):
	name(name), grade_sign_req(grade_sign_req),
	grade_exec_req(grade_exec_req), is_signed(false)
{
	if (grade_sign_req < 1 || grade_exec_req < 1)
	{
		std::cout <<
			"Cannot create form, requirement is too high."
		<< std::endl;
		throw GradeTooHighException();
	}
	if (grade_sign_req > 150 || grade_exec_req > 150)
	{
		std::cout <<
			"Cannot create form, requirement is too low."
		<< std::endl;
		throw GradeTooLowException();
	}
	std::cout <<
		"We got a " << name << " form."
	<< std::endl;
}

Form::Form(const Form &copied): 
	name(copied.name), grade_sign_req(copied.grade_sign_req),
	grade_exec_req(copied.grade_exec_req), is_signed(copied.is_signed)
{
	std::cout <<
		"We made a copy of our " << name << "form. Thats useful somehow."
	<< std::endl;
}

Form::~Form(void)
{
	std::cout <<
		"A " << name << " form got shredded."
	<< std::endl;
}

std::string const& Form::getName(void) const
{
	return name;
}

int const& Form::getGradeSignReq(void) const
{
	return grade_sign_req;
}

int const& Form::getGradeExecReq(void) const
{
	return grade_exec_req;
}

bool const& Form::getIsSigned(void) const
{
	return is_signed;
}

void	Form::beSigned(Bureaucrat& signee)
{
	if (is_signed)
	{
		std::cout <<
			"Bureaucrat " << signee.getName() <<
	 		" attempted to sign already-signed form " << name
		<< std::endl;
		throw DoubleSigningException();
	}

	if (signee.getGrade() > grade_sign_req)
	{
		std::cout <<
			"Bureaucrat " << signee.getName() << " (grade " << signee.getGrade() << ")" <<
			" failed to sign form " << name << " of higher grade " << getGradeSignReq() << "."
		<< std::endl;
		throw GradeTooLowException();
	}

	is_signed = true;
	std::cout <<
		"Bureaucrat " << signee.getName() << " signed " << name << "."
	<< std::endl;
}

Form::DoubleSigningException::DoubleSigningException(void): std::logic_error("Form already signed")
{
}

Form::GradeTooHighException::GradeTooHighException(void): std::out_of_range("Grade too high")
{
}

Form::GradeTooLowException::GradeTooLowException(void): std::out_of_range("Grade too low")
{
}

std::ostream	&operator<<(std::ostream &ostream, Form &form)
{
	ostream <<
		form.getName() <<
		", " << (form.getIsSigned() ? "signed" : "unsigned") << " form"
		" of signing requirement of " << form.getGradeSignReq() <<
		" and executing requirement of " << form.getGradeExecReq() << ".";
	return ostream;
}
