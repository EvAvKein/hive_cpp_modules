/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:02 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:06:18 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main (void)
{
	{
		std::cout << "< TEST FROM SUBJECT >" << std::endl;
		const Animal* meta = new(std::nothrow) Animal();
		if (!meta)
			return 1;
		const Animal* j = new(std::nothrow) Dog();
		if (!j)
		{
			delete meta;
			return 1;
		}
		const Animal* i = new(std::nothrow) Cat();
		if (!i)
		{
			delete meta;
			delete j;
			return 1;
		}

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "< COPY CONSTRUCTOR TEST >" << std::endl;
		Animal generic("GENERIC");
		Animal diff(generic);
	}
	std::cout << std::endl;
	{
		std::cout << "< DEFAULT CONSTRUCTOR ANIMAL `makeSound` TEST >" << std::endl;
		Animal generic;
		generic.makeSound();
	}
	std::cout << std::endl;
	{
		std::cout << "< TYPE-PARAM CONSTRUCTOR ANIMAL `makeSound` TEST >" << std::endl;
		Animal weird("Weird");
		weird.makeSound();
	}
	std::cout << std::endl;
	{
		std::cout << "< CAT `makeSound` TEST >" << std::endl;
		Cat kitty;
		kitty.makeSound();
	}
	std::cout << std::endl;
	{
		std::cout << "< WRONG ANIMAL & WRONG CAT `makeSound` TEST >" << std::endl;
		
		const WrongAnimal* meta = new(std::nothrow) WrongAnimal();
		if (!meta)
			return 1;
		const WrongAnimal* i = new WrongCat();
		if (!i)
		{
			delete meta;
			return 1;
		}

		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();

		delete meta;
		delete i;
	}
}
