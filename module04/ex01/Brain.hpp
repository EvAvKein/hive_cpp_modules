/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:00 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 20:44:45 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(std::string ideas[100]);
		Brain(const Brain& copied);
		Brain &operator=(const Brain& assigned);
		virtual ~Brain(void);
		
	protected:
		std::string		ideas[100];
};

#endif
