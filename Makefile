# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:12:38 by marcogar          #+#    #+#              #
#    Updated: 2023/06/05 16:41:04 by marcogar         ###   ########.fr        #
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
SL = main.c\
	 error.c\
	 ft_valid_map.c\
	 ft_valid_map_utils.c\
	 ft_print_map.c
SRC_SL = $(addprefix src/, $(SL))
OBJ_SL = $(SRC_SL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SL) $(OBJ_GNL)
	@make -C libft/
	@make -C ft_printf/
	@$(CC) $(CFLAGS) $(SLFLAGS) $(OBJ_GNL) $(OBJ_SL) -o $(NAME) $(LIBFT_LIB) $(PRINTF_LIB)

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@$(RM) $(OBJ_SL) $(OBJ_GNL)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all