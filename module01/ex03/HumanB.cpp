/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:32:10 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 17:30:40 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(nullptr)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
