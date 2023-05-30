# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:12:38 by marcogar          #+#    #+#              #
#    Updated: 2023/05/30 12:24:22 by marcogar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
SLFLAGS = -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB = libft/libft.a
PRINTF_LIB = ft_printf/ft_printf.a

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix get_next_line/, $(GNL))
OBJ_GNL = $(SRC_GNL:.c=.o)

SRC_GAME = main.c
OBJ_GAME = $(SRC_GAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_GAME) $(OBJ_GNL)
	@make -C libft/
	@make -C ft_printf/
	@$(CC) $(CFLAGS) $(SLFLAGS) $(LIBFT_LIB) $(PRINTF_LIB) $(OBJ_GNL) $(OBJ_GAME) -o $(NAME)

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@$(RM) $(OBJ_GAME) $(OBJ_GNL)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all