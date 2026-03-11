# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 08:27:25 by mhidani           #+#    #+#              #
#    Updated: 2026/03/11 15:11:00 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook
AUTHOR		= mhidani
SINCE		= 2026.03.03
VERSION		= 1.0.0v
LOCAL		= 42sp

SRC_DIR		= src
INC_DIR		= include
OBJ_DIR		= obj

FILES		= PhoneBook.cpp Contact.cpp main.cpp
SRC			= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
CPPINC		= -I $(INC_DIR)/
MKDIR		= mkdir
MKDFLAGS	= --parents
RM			= rm
RMFLAGS		= --force --recursive

all: banner $(NAME)

$(NAME): $(OBJ) | $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) $(OBJ) $(CPPINC) -o $@
	@echo "$(NAME): is done 🛸"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(MKDIR) $(MKDFLAGS) $(dir $@)
	@$(CPP) $(CPPFLAGS) $(CPPINC) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(MKDFLAGS) $@
	@echo "$@: directory was created 📁"

banner:
	@echo "CPP-00 Exercise 01 (Milestone 4)"
	@echo "$(NAME) - $(VERSION), $(LOCAL)"
	@echo "$(AUTHOR) - $(SINCE)"

clean:
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@echo "$(OBJ_DIR): is cleaned  🧹"

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "$(NAME): is cleaned 🧹"

re: fclean all

.PHONY: clean fclean all re banner