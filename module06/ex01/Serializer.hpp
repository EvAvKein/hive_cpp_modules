/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/27 15:21:32 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
public:
	Serializer(void) = delete;
	Serializer(Serializer const &copied) = delete;
	Serializer &operator=(Serializer const &assigned) = delete;
	~Serializer(void) = delete;

	static	uintptr_t	serialize(Data* ptr);
	static	Data*		deserialize(uintptr_t raw);
};

#endif
