# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 11:00:43 by ekeinan           #+#    #+#              #
#    Updated: 2025/09/19 11:01:47 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RPN

SRC := main.cpp \
	   RPN.cpp
HEADERS := RPN.hpp

CC := c++
COMPILE_FLAGS := -Wall -Wextra -Werror -std=c++20
VERBOSE_FLAGS := -D VERBOSE=1
DEBUG_FLAGS := -g

OBJ := $(SRC:%.cpp=%.o)

# STANDARD #
all: $(NAME)

%.o: %.cpp
	${CC} $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	${CC} $(COMPILE_FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# EXTRAS #
neat: $(NAME) clean
	clear

verbose: COMPILE_FLAGS += $(VERBOSE_FLAGS)
verbose: re

debug: COMPILE_FLAGS += $(DEBUG_FLAGS)
debug: re

# PHONY #
.PHONY: all clean fclean re neat debug
