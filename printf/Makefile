# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 10:02:01 by tpoungla          #+#    #+#              #
#    Updated: 2022/11/07 10:02:01 by tpoungla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall  -Wextra -Werror

SRCS = ft_printf.c ft_putnbr_id.c ft_putchar_c.c ft_percent.c ft_strlen.c ft_putstr_s.c ft_putnbr_u.c ft_putnbr_lx16.c ft_putnbr_ux16.c ft_putnbr_p.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
re: fclean all