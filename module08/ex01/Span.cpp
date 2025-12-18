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

void Span::addNumber(int n)
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
	unsigned long long shortest = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < array.size(); i++)
	{
		unsigned long long gap = static_cast<long long>(array[i]) - static_cast<long long>(array[i - 1]);
		shortest = std::min(shortest, gap);
	}
	return shortest;
}

unsigned int Span::longestSpan(void)
{
	if (array.size() < 2)
		throw std::logic_error("Span has insufficient size for longestSpan check");
	return array[array.size() - 1] - array[0];
}
