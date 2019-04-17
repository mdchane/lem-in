# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 12:57:11 by sarobber          #+#    #+#              #
#    Updated: 2019/04/17 17:36:03 by sarobber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu


HEADER_NAME = visu.h

CC = gcc

FLAGS = -g -Wall -Werror -Wextra

HEADER_PATH = include

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

MLX = -framework OpenGL -framework AppKit

SRC_PATH = srcs

SRC_NAME = main_v.c draw.c parsing_v.c room_utils.c parsing_utils_v.c create_ants.c draw_ants.c create_path.c
OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ_PATH) $(OBJ) $(HEADER)
	@make -j -C ../libft/
	@make -C minilibx_macos/
	@$(info $(NAME) : Sources compiling...)
	@$(CC) $(FLAGS) $(OBJ) -o $@ -L../libft -lft minilibx_macos/libmlx.a $(MLX)
	@$(info Executable $(NAME) made)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -I $(HEADER_PATH) -I ../libft/includes -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $@

clean:
	@make -C ../libft/ fclean
	@rm -rf $(OBJ_PATH) || true
	@$(info $(OBJ_PATH) deleted)

fclean: clean
	@rm -f $(NAME)
	@$(info Executable $(NAME) deleted)

re: fclean all
	@echo "Make re done"

.PHONY: all lib clean fclean re
