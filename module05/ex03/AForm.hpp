/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/13 15:50:41 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			grade_sign_req;
		const int			grade_exec_req;
		bool				is_signed;

	protected:
		void	throwIfCantExecForm(Bureaucrat const& executor) const;

	public:
		AForm(void);
		AForm(std::string const& name, int const& grade_sign_req, int const& grade_exec_req);
		AForm(AForm const& copied);
		AForm &operator=(const AForm& assigned) = delete;
		virtual ~AForm(void);

		std::string const&	getName(void)			const;
		int const&			getGradeSignReq(void)	const;
		int const&			getGradeExecReq(void)	const;
		bool const&			getIsSigned(void)		const;

		void				beSigned(Bureaucrat const& signee);
		virtual void		execute(Bureaucrat const& executor) const = 0;

		class DoubleSigningException: public std::logic_error
		{
			public:
				DoubleSigningException(void);
		};
		class GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException(void);
		};
		class GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException(void);
		};
};

std::ostream	&operator<<(std::ostream &ostream, AForm &form);

#endif
