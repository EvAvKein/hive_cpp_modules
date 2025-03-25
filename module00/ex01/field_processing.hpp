/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_processing.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:55:41 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/25 18:11:05 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_PARSING_HPP
# define FIELD_PARSING_HPP

# include <iostream>
# include <cstdarg>

typedef std::string*(*str_parser)(std::string*);

std::string	*vaguely_phonenum(std::string *str);
std::string	*not_empty(std::string *str);
std::string	*trim(std::string *str);

std::string	receive_field(std::string prompt, str_parser* validation);

#endif