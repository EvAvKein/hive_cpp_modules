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

# include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat boss("Boss", 2);

	boss.incrementGrade();
	try {
		boss.incrementGrade();
	} catch (std::exception &e) {
		std::cerr <<
			boss.getName() << " " << e.what() <<
			" (tried to increment past " << boss.getGrade() << ")"
		<< std::endl;
	}
	std::cout << boss << std::endl;

	boss.decrementGrade();
	std::cout << boss << std::endl;

	Bureaucrat jack;
	try {
		jack.decrementGrade();
	} catch (std::exception &e) {
		std::cerr <<
			jack.getName() << " " << e.what() <<
			" (tried to decrement past " << jack.getGrade() << ")"
		<< std::endl;
	}
	std::cout << '\n';

	Bureaucrat newbie1("John", 42);
	Bureaucrat newbie2 = newbie1;
	std::cout <<
		newbie1 <<
		newbie2
	<< std::endl;

	return (EXIT_SUCCESS);
}
