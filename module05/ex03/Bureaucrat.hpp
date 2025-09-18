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

# ifndef AForm
	class AForm;
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
		Bureaucrat(Bureaucrat const& copied);
		Bureaucrat &operator=(const Bureaucrat& assigned) = delete;
		virtual ~Bureaucrat(void);

		std::string const&	getName(void)	const;
		int const&			getGrade(void)	const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(AForm& form) const;
		void	executeForm(AForm const& form) const;

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

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat const& bureaucrat);

#endif
