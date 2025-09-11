/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:42 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include <exception>

int	main(void)
{
	Bureaucrat	boss("Boss", 2);

	Form		*form;

	try {
		form = new Form("Impossibly low Form", 0, 42);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		form = new Form("Tippity-top Form", 1, 42);
	} catch (std::exception &e) {
		// TODO:
		return (1);
	}
	
	std::cout << *form << std::endl;
	try {
		boss.signForm(*form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	delete form;

	form = new Form("Signable Form", 2, 24);
	std::cout << *form << std::endl;
	try {
		boss.signForm(*form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	Form		form_copy(*form);
	delete form;
	std::cout << form_copy << std::endl;
	
	form = new Form();
	std::cout << *form << std::endl;
	try {
		boss.signForm(*form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	delete form;
	
	try {
		form = new Form("Impossibly low Form", 3, 200);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
