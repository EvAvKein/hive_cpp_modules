/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:33:12 by ekeinan           #+#    #+#             */
/*   Updated: 2025/11/27 15:43:45 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	Data data = {-2};
	uintptr_t serialized = Serializer::serialize(&data);
	printf("%i\n", Serializer::deserialize(serialized)->datum);
}
