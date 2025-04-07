/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:47:28 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/07 15:21:55 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# if COLOR
#  define CLR_RESET		"\e[0m"
#  define CLR_PRP		"\e[35m"
#  define CLR_GRN		"\e[32m"
#  define CLR_BRN		"\e[33m"
# else
#  define COLOR 0
#  define CLR_RESET		""
#  define CLR_PRP		""
#  define CLR_GRN		""
#  define CLR_BRN		""
# endif

int main()
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringVAR;
	std::string& stringREF = stringVAR;
	

	std::cout << "Addresses:" << std::endl;
	std::cout << CLR_BRN "VAR: " CLR_RESET << &stringVAR << std::endl;
	std::cout << CLR_PRP "PTR: " CLR_RESET << stringPTR << std::endl;
	std::cout << CLR_GRN "REF: " CLR_RESET << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << CLR_BRN "VAR: " CLR_RESET << stringVAR << std::endl;
	std::cout << CLR_PRP "PTR: " CLR_RESET << *stringPTR << std::endl;
	std::cout << CLR_GRN "REF: " CLR_RESET << stringREF << std::endl;
}
