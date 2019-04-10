# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 09:49:18 by mdchane           #+#    #+#              #
#    Updated: 2019/04/10 10:57:58 by sarobber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

HEADER_NAME = liblem_in.h

CC = gcc

FLAGS = -g -Wall -Werror -Wextra

HEADER_PATH = includes

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

SRC_PATH = src

SRC_NAME = main.c parse_utils.c parsing.c graph_utils.c\
	free.c path_utils.c print.c read.c edmonds.c \
	create_tab.c pack.c pack_utils.c move_ant.c move.c \
	print_ants.c

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ) $(HEADER)
	@make -j -C libft/
	@$(info $(NAME) : Sources compiling...)
	@$(CC) $(FLAGS) $(OBJ) -o $@ -Llibft -lft
	@$(info Executable $(NAME) made)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -I $(HEADER_PATH) -I libft/includes -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $@

clean:
	@make -C libft/ fclean
	@rm -rf $(OBJ_PATH) || true
	@$(info $(OBJ_PATH) deleted)

fclean: clean
	@rm -f $(NAME)
	@$(info Executable $(NAME) deleted)

re: fclean all
	@echo "Make re done"

.PHONY: all lib clean fclean re
