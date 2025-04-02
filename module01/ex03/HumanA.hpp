/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:56:02 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 16:47:53 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();

	private:
		std::string name;
		Weapon &weapon;
};

#endif
