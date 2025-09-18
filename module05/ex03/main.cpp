/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/09/18 11:42:22 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	Intern stanley;

	AForm	*form = nullptr;

	try {
		form = stanley.makeForm("UnFORMulated", "The Boss");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Form pointer is " << form << std::endl;

	std::cout << '\n';

	try {
		form = stanley.makeForm("Shrubbery Creation", "empty field");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << *form << std::endl;
	delete form;

	std::cout << '\n';

	try {
		form = stanley.makeForm("Robotomy Request", "Roboto");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << *form << std::endl;
	delete form;

	std::cout << '\n';

	try {
		form = stanley.makeForm("Presidential Pardon", "Luigi");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << *form << std::endl;
	delete form;

	return (EXIT_SUCCESS);
}
