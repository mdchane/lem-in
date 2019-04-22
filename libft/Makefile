# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 08:36:51 by mdchane           #+#    #+#              #
#    Updated: 2019/04/22 16:53:19 by mdchane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER_NAME = libft.h libftprintf.h

SRC_NAME = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_isupper.c\
		ft_islower.c\
		ft_pow.c\
		ft_sqrt.c\
		ft_foreach.c\
		ft_strrev.c\
		ft_itoa_base.c\
		ft_putnchar.c\
		ft_putstr_to_n.c\
		ft_strupper.c\
		ft_ftoa.c\
		get_next_line.c\
		printf.c \
		get_format.c \
		printf_format.c \
		utils.c \
		int_precision.c \
		aff_c.c \
		aff_p.c \
		aff_di.c \
		aff_percent.c \
		aff_o.c \
		aff_s.c \
		aff_u.c \
		aff_x.c \
		aff_f.c


HEADER_PATH = includes

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

SRC_PATH = srcs

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS) $(HEADER)
	@$(info $(NAME) : Sources compiling...)
	@ar rcs $(NAME) $(OBJS)
	@$(info $(NAME) made)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	@gcc $(FLAGS) -I $(HEADER_PATH) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
