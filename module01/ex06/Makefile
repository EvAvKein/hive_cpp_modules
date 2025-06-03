# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 19:12:41 by ekeinan           #+#    #+#              #
#    Updated: 2025/06/03 11:03:08 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := harlFilter

SRC := main.cpp \
	   Harl.cpp
HEADERS := Harl.hpp

CC := c++
COMPILE_FLAGS := -Wall -Wextra -Werror -std=c++11
DEBUG_FLAGS := -g

OBJ := $(SRC:%.cpp=%.o)

# STANDARD #
all: $(NAME)

%.o: %.cpp
	$(CC) $(COMPILE_FLAGS) -D COLOR=$(if $(COLOR),1,0) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(COMPILE_FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# EXTRAS #
neat: $(NAME) clean
	clear

color: export COLOR = 1
color: re

debug: COMPILE_FLAGS += $(DEBUG_FLAGS)
debug: re

# PHONY #
.PHONY: all clean fclean re neat color debug
