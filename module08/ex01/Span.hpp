/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/13 15:50:12 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span
{
public:
	Span(void);
	Span(Span const &copied);
	Span &operator=(Span const &assigned);
	~Span(void);

	Span(unsigned int capacity);

	template <typename T>
	void addRange(typename T::iterator begin, typename T::iterator end)
	{
		size_t rangeSize = std::distance(begin, end);
		if (array.size() + rangeSize > capacity)
			throw std::runtime_error("Span's remaining capacity cannot contain incoming Range");
		array.insert(array.end(), begin, end);
		std::sort(array.begin(), array.end());
	}

private:
	unsigned int capacity;
	std::vector<int> array;

	void addNumber(unsigned int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif
