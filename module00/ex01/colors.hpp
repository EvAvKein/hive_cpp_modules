/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:31:29 by ekeinan           #+#    #+#             */
/*   Updated: 2025/04/01 21:39:57 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COLORS_HPP
# define COLORS_HPP

# if COLOR
#  define CLR_RESET			"\e[0m"
#  define CLR_DIM 			"\e[2;37m"
#  define CLR_DIMBOLD		"\e[2;1;37m"
#  define CLR_CYNBGBOLD		"\e[7;1;36;40m"
#  define CLR_CYNBOLD		"\e[1;36m"
#  define CLR_YLLWBOLD		"\e[1;33m"
#  define CLR_REDBOLD		"\e[1;31m"
#  define CLR_GREENBOLD		"\e[1;32m"
# else
#   define COLOR 0
#   define CLR_RESET		""
#   define CLR_DIM 			""
#   define CLR_DIMBOLD		""
#   define CLR_CYNBOLD		""
#   define CLR_CYNBGBOLD	""
#   define CLR_YLLWBOLD		""
#   define CLR_REDBOLD		""
#   define CLR_GREENBOLD	""
# endif

#endif