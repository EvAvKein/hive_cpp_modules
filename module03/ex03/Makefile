# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 19:12:41 by ekeinan           #+#    #+#              #
#    Updated: 2025/06/17 19:36:53 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := diamondtrap

SRC := main.cpp \
	   ClapTrap.cpp \
	   ScavTrap.cpp \
	   FragTrap.cpp \
	   DiamondTrap.cpp
HEADERS := ClapTrap.hpp \
		   ScavTrap.hpp \
		   FragTrap.hpp \
		   DiamondTrap.hpp

CC := c++
COMPILE_FLAGS := -Wall -Wextra -Werror -Wshadow -std=c++20
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

debug: COMPILE_FLAGS += $(DEBUG_FLAGS)
debug: re

# PHONY #
.PHONY: all clean fclean re neat debug
