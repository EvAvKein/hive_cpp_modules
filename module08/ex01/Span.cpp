/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/14 12:08:50 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <stdexcept>
#include <algorithm>

Span::Span(void) : capacity(0)
{
}

Span::Span(Span const &copied) : capacity(copied.capacity), array(copied.array)
{
}

Span &Span::operator=(Span const &assigned)
{
	if (this != &assigned)
	{
		capacity = assigned.capacity;
		array = assigned.array;
	}
	return *this;
}

Span::~Span(void)
{
}

Span::Span(unsigned int capacity) : capacity(capacity)
{
}

void Span::addNumber(unsigned int n)
{
	if (array.size() >= capacity)
		throw std::runtime_error("Span is at capacity, cannot add number");
	array.insert(array.end(), n);
	std::sort(array.begin(), array.end());
}

unsigned int Span::shortestSpan(void)
{
	if (array.size() < 2)
		throw std::logic_error("Span has insufficient size for shortestSpan check");
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < array.size(); i++)
		shortest = std::min(shortest, array[i] - array[i - 1]);
	return shortest;
}

unsigned int Span::longestSpan(void)
{
	if (array.size() < 2)
		throw std::logic_error("Span has insufficient size for longestSpan check");
	return array[array.size() - 1] - array[0];
}
