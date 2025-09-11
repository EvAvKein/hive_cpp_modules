/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

# ifndef Form
	class Form;
# endif

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		// Could've made the grade type `u_int8_t`,
		// but those wouldn't print to ostream without weird explicit plus signs

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(const Bureaucrat& copied);
		Bureaucrat &operator=(const Bureaucrat& assigned) = delete;
		virtual ~Bureaucrat(void);

		std::string const&	getName(void)	const;
		int const&			getGrade(void)	const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form& form);

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

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat &bureaucrat);

#endif
