/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/27 15:43:56 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t			Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
};

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
};
