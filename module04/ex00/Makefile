# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 19:12:41 by ekeinan           #+#    #+#              #
#    Updated: 2025/06/26 14:51:23 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := catdog

SRC := main.cpp \
	   Animal.cpp \
	   Cat.cpp	\
	   Dog.cpp \
	   WrongAnimal.cpp \
	   WrongCat.cpp
HEADERS := Animal.hpp \
		   Cat.hpp \
		   Dog.hpp \
		   WrongAnimal.cpp \
		   WrongCat.hpp

CC := c++
COMPILE_FLAGS := -Wall -Wextra -Werror -std=c++20
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
