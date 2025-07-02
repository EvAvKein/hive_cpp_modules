/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:00 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:11:20 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: virtual public Animal
{
	public:
		Dog(void);
		Dog(const Dog& copied);
		Dog &operator=(const Dog& assigned);
		virtual ~Dog(void);

		void makeSound(void) const override;
};

#endif
