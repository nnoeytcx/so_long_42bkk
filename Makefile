# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 06:43:19 by tpoungla          #+#    #+#              #
#    Updated: 2023/05/30 15:30:17 by tpoungla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -g 

CC = gcc

FILES = src/main.c src/get_map.c src/map_check.c \
src/map_util.c gnl/get_next_line.c \
gnl/get_next_line_utils.c src/showwindow.c src/hook.c \
src/move.c printf/ft_printf.c printf/ft_percent.c \
printf/ft_putchar_c.c printf/ft_putnbr_id.c printf/ft_putnbr_lx16.c \
printf/ft_putnbr_p.c printf/ft_putnbr_u.c printf/ft_putnbr_ux16.c \
printf/ft_putstr_s.c printf/ft_strlen.c libft/ft_strrchr.c \
libft/ft_strlen.c libft/ft_strncmp.c

MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJ	:= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx/
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(MLX_FLAG)

norm:
	norminette -R checkforbiddensourceheader $(FILES)
	norminette -R checkdefine src/solong.h
clean:
	@make clean -C mlx/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re norm