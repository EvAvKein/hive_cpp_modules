/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/13 15:50:12 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <class T>
void	swap(T& first, T& second)
{
	T temp = first;
	first = second;
	second = temp;
}

template <class T>
T&	min(T& first, T& second)
{
	return (first < second ? first : second);
}

template <class T>
T&	max(T& first, T& second)
{
	return (first > second ? first : second);
}

#endif
