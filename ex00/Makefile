# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 10:33:07 by mhidani           #+#    #+#              #
#    Updated: 2026/02/24 19:48:52 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
AUTHOR		= mhidani
SINCE		= 2026.02.21
VERSION		= 1.0.0v
LOCAL		= 42sp

SRC_DIR		= src
OBJ_DIR		= obj

FILES		= megaphone.cpp
SRC			= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
MKDIR		= mkdir
MKDFLAGS	= --parents
RM			= rm
RMFLAGS		= --force --recursive

all: banner $(NAME)

$(NAME): $(OBJ) | $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $@
	@echo "$(NAME): is done 🛸"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(MKDIR) $(MKDFLAGS) $(dir $@)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(MKDFLAGS) $@
	@echo "$@: directory was created 📁"

banner:
	@echo "CPP-00 (Milestone 4)"
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
