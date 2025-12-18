/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/12/18 11:33:20 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <limits>

class Span
{
public:
	Span(void);
	Span(Span const &copied);
	Span &operator=(Span const &assigned);
	~Span(void);

	Span(unsigned int capacity);

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
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
};

#endif
