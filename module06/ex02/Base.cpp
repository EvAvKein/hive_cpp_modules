/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/28 14:09:56 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
};

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	srand(time(NULL));
	const int	generated = rand();
	const int	third = RAND_MAX / 3;

	if (generated < third)
		return new A();
	if (generated < third * 2)
		return new B();
	else
		return new C();
};

void	identify(Base* p)
{
		if (dynamic_cast<A*>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "C" << std::endl;
		else
			std::cout << "[UNKNOWN]" << std::endl;
};

void	identify(Base& p)
{
	try {
		Base casted = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (...) {};
	try {
		Base casted = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...) {};
	try {
		Base casted = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (...) {};

	std::cout << "[UNKNOWN]" << std::endl;
};
