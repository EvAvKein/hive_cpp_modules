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
#include <exception>

/**
 * NOTE: About usage of std::nothrow
 * 
 * Using std::nothrow to more closely match the subject's provided code,
 * as using try-catch with proper cleanup would require declaration
 * outside the try-catch block and assignment inside inside, meaning
 * that they can't be constant and then it wouldn't validate
 * getType()'s const.
 */

// NOTE: Uncomment the code sections below
// to see that the Animal class is now abstract

int main (void)
{
	{
		std::cout << "< TEST FROM SUBJECT >" << std::endl;
		// const Animal* meta = new(std::nothrow) Animal();
		// if (!meta)
		// {
		// 	std::cout << "Memory allocation failed, aborting..." << std::endl;
		// 	return 1;
		// }
		const Animal* j = new(std::nothrow) Dog();
		if (!j)
		{
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			// delete meta;
			return 1;
		}
		const Animal* i = new(std::nothrow) Cat();
		if (!i)
		{
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			// delete meta;
			delete j;
			return 1;
		}

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		// meta->makeSound();

		// delete meta;
		delete j;
		delete i;
	}
	// std::cout << std::endl;
	// {
	// 	std::cout << "< COPY CONSTRUCTOR TEST >" << std::endl;
	// 	Animal generic("GENERIC");
	// 	Animal diff(generic);
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << "< DEFAULT CONSTRUCTOR ANIMAL `makeSound` TEST >" << std::endl;
	// 	Animal generic;
	// 	generic.makeSound();
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << "< TYPE-PARAM CONSTRUCTOR ANIMAL `makeSound` TEST >" << std::endl;
	// 	Animal weird("Weird");
	// 	weird.makeSound();
	// }
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
		{
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			return 1;
		}
		const WrongAnimal* i = new(std::nothrow) WrongCat();
		if (!i)
		{
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			delete meta;
			return 1;
		}
		const WrongCat* j = new(std::nothrow) WrongCat();
		if (!j)
		{
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			delete meta;
			delete i;
			return 1;
		}

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	{
		std::cout << "< ARRAY TEST AS PER SUBJECT >" << std::endl;
		
		Animal *pets[10] = {};

		try {
			for (int i = 0; i < 10; i++)
			{
				if (i % 2)
					pets[i] = new Cat();
				else
					pets[i] = new Dog();
			}
		} catch (std::exception& e) {
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			for (int i = 0; i < 10; i++)
				delete pets[i];
			return 1;
		}

		std::cout << "The pets are all here!" << std::endl;

		for (int i = 0; i < 10; i++)
			delete pets[i];
	}
	std::cout << std::endl;
	{
		std::cout << "< COPY TEST AS PER SUBJECT >" << std::endl;
		
		Cat* originalCat;
		Cat* copyCat;
		try {
			originalCat = new Cat();
			copyCat = new Cat(*originalCat);
		} catch (std::exception& e) {
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			delete originalCat;
			delete copyCat;
			return 1;
		}
		delete originalCat;
		delete copyCat;
	}
	std::cout << std::endl;
	{
		std::cout << "< NO LEAKS TEST FROM SUBJECT >" << std::endl;
		
		Animal* j;
		Animal* i;
		try {
			j = new Dog();
			i = new Cat();
		} catch (std::exception& e) {
			std::cout << "Memory allocation failed, aborting..." << std::endl;
			delete j;//should not create a leak
			delete i;
			return 1;
		}
		delete j;//should not create a leak
		delete i;
	}
}

