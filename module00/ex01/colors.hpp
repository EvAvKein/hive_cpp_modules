/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:31:29 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/28 18:03:46 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# if COLOR
#  define CLR_RESET			"\e[0m"
#  define CLR_BACKGROUND	"\e[7m"
#  define CLR_YLLWBGBOLD	"\e[7;1;33m"
#  define CLR_DIM 			"\e[2;37m"
#  define CLR_DIMBOLD		"\e[2;1;37m"
#  define CLR_RED			"\e[0;31m"
#  define CLR_REDBOLD		"\e[1;31m"
#  define CLR_GREEN			"\e[0;32m"
#  define CLR_GREENBOLD		"\e[1;32m"
# else
#   define COLOR 0
#   define CLR_RESET		""
#   define CLR_BACKGROUND	""
#   define CLR_YLLWBGBOLD	""
#   define CLR_DIM 			""
#   define CLR_DIMBOLD		""
#   define CLR_RED			""
#   define CLR_REDBOLD		""
#   define CLR_GREEN		""
#   define CLR_GREENBOLD	""
# endif

#endif