/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <class T>
class Array
{
	private:
		T* vector;

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const& copied);
		Array &operator=(Array const& assigned);
		~Array(void);

		Array &operator[](unsigned int index);

		unsigned int size(void) const;
};

#endif
