/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:26:31 by ekeinan           #+#    #+#             */
/*   Updated: 2025/07/03 18:38:32 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(void) = delete;
		AMateria(std::string const & type);
		AMateria(const AMateria& copied);
		AMateria &operator=(const AMateria& assigned);
		virtual ~AMateria(void);
		

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif

