/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/13 15:50:12 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <optional>

template <typename T>
std::optional<typename T::iterator> easyfind(T &container, int value)
{
	typename T::iterator found = std::find(container.begin(), container.end(), value);
	if (found == container.end())
		return std::nullopt;
	return std::optional<typename T::iterator>(found);
}

template <typename T>
typename T::const_iterator easyfind(const T &container, const int value)
{
	typename T::const_iterator found = std::find(container.begin(), container.end(), value);
	if (found == container.end())
		return std::nullopt;
	return std::optional<typename T::iterator>(found);
}

#endif
