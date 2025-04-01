/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:47:28 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 11:52:33 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main()
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringVAR;
	std::string& stringREF = stringVAR;
	

	std::cout << "Addresses:" << std::endl;
	std::cout << "VAR: " << &stringVAR << std::endl;
	std::cout << "PTR: " << stringPTR << std::endl;
	std::cout << "REF: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << "VAR: " << stringVAR << std::endl;
	std::cout << "PTR: " << *stringPTR << std::endl;
	std::cout << "REF: " << stringREF << std::endl;
}
