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

int	main(void)
{
	Bureaucrat	boss("Boss", 2);
	Form		*form;

	try {
		form = new Form("Impossibly high Form", 0, 42);
	} catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		form = new Form("Tippity-top Form", 1, 42);
	} catch (std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	

	std::cout << '\n';


	std::cout << *form << std::endl;
	try {
		boss.signForm(*form);
	} catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	delete form;


	std::cout << '\n';


	try {
		form = new Form("Signable Form", 2, 24);
	} catch (std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << *form << std::endl;
	boss.signForm(*form);
	std::cout << *form << std::endl;
	Form		form_copy(*form);
	delete form;
	std::cout << form_copy << std::endl;


	std::cout << '\n';


	try {
		form = new Form();
	} catch (std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << *form << std::endl;
	boss.signForm(*form);
	std::cout << *form << std::endl;
	try {
		boss.signForm(*form);
	} catch (Form::DoubleSigningException &e) {
		std::cerr << e.what() << std::endl;
	}
	delete form;


	std::cout << '\n';


	try {
		form = new Form("Impossibly low Form", 3, 200);
	} catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
