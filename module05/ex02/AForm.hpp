/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/06 18:04:07 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		const int			grade_sign_req;
		const int			grade_exec_req;
		bool				is_signed;

	public:
		AForm(void);
		AForm(std::string const& name, int grade_sign_req, int grade_exec_req);
		AForm(const AForm& copied);
		AForm &operator=(const AForm& assigned) = delete;
		virtual ~AForm(void);

		std::string const&	getName(void)			const;
		int const&			getGradeSignReq(void)	const;
		int const&			getGradeExecReq(void)	const;
		bool const&			getIsSigned(void)		const;

		void	beSigned(Bureaucrat& signee);

		class DoubleSigningException: public std::logic_error
		{
			public:
				DoubleSigningException(void);
				const char* what(void) const throw();
		};
		class GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException(void);
				const char* what(void) const throw();
		};
		class GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException(void);
				const char* what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &ostream, AForm &form);

#endif
