/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:32:10 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 16:43:10 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
