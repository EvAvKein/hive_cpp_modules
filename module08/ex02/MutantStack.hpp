/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stdexcept>

template <class T>
class MutantStack
{
	private:
		T* vector = nullptr;
		unsigned int vecSize = 0;

	public:
		MutantStack(void): vector(new T[1])
		{
		};

		MutantStack(unsigned int n)
		{
			if (n == 0)
				throw std::length_error("MutantStack initialization attempted with size 0");
			vecSize = n;
			vector = new T[n];
		};

		MutantStack(MutantStack const& copied)
		{
			vecSize = copied.size();
			vector = new T[vecSize];
			for (unsigned int i = 0; i < vecSize; i++)
				vector[i] = copied[i];
		};

		MutantStack &operator=(MutantStack const& assigned)
		{
			if (assigned == *this)
				return ;

			delete vector;
			vecSize = assigned.size();
			vector = new T[vecSize];
			for (unsigned int i = 0; i < vecSize; i++)
				vector[i] = assigned[i];

			return *this;
		};

		~MutantStack(void)
		{
			delete vector;
		};

		T &operator[](unsigned int index)
		{
			if (index >= vecSize)
				throw std::out_of_range("MutantStack indexed out of bounds");
			return vector[index];
		};

		const T operator[](unsigned int index) const
		{
			if (index >= vecSize)
				throw std::out_of_range("MutantStack indexed out of bounds");
			return vector[index];
		};

		unsigned int size(void) const
		{
			return vecSize;
		};
};

#endif
