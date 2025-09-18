/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp  	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/17 11:55:04 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <random>

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;

	public:
		RobotomyRequestForm(void) = delete;
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& copied);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& assigned) = delete;
		virtual ~RobotomyRequestForm(void) = default;

		void	execute(Bureaucrat const& executor) const;
};

#endif
