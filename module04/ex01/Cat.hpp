/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:00 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:11:20 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: virtual public Animal
{
	public:
		Cat(void);
		Cat(const Cat& copied);
		Cat &operator=(const Cat& assigned);
		virtual ~Cat(void);

		void makeSound(void) const override;
};

#endif
