/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:56:05 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 16:52:10 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string getType();
		void setType(std::string);

	private:
		std::string type;
};

#endif
