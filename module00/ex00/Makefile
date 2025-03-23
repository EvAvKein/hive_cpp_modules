# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 19:12:41 by ekeinan           #+#    #+#              #
#    Updated: 2025/03/23 13:22:27 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

SRC_FILES := megaphone.cpp

CC := c++
COMPILE_FLAGS := -Wall -Wextra -Werror -std=c++11

OBJ := $(SRC_FILES:%.cpp=%.o)

all: $(NAME)

%.o: %.c
	${CC} $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	${CC} $(COMPILE_FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
