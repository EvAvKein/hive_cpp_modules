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

void Span::addNumber(unsigned int n)
{
	if (array.size() >= capacity)
		throw std::runtime_error("Span is at capacity, cannot add number");
	array.push_back(n);
}

unsigned int Span::shortestSpan(void)
{
	return 0;
}

unsigned int Span::longestSpan(void)
{
	return 0;
}
