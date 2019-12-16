# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 18:14:59 by iklimov           #+#    #+#              #
#    Updated: 2019/12/16 12:23:10 by skrasin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLG = -Wextra -Wall -Werror
SRCS = fillit.c error.c solve.c reader.c ft_isqrtc.c
LIB = Libft/libft.a

all: $(NAME)

$(NAME):
	make -s -C Libft
	gcc $(CFLG) $(SRCS) $(LIB) -o $(NAME)

clean:
	make -C Libft clean

fclean:
	rm -f $(NAME)
	make -s -C Libft fclean

re:	fclean $(NAME)

.PHONY: all clean fclean re