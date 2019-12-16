# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svet <svet@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 18:14:59 by iklimov           #+#    #+#              #
#    Updated: 2019/12/16 11:22:44 by svet             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLG = -Wextra -Wall -Werror
SRCS = fillit.c error.c solve.c reader.c ft_isqrtc.c
LIB = Libft/libft.a

all: $(NAME)

$(NAME):
	make -s -C libft
	gcc $(CFLG) $(SRCS) $(LIB) -o $(NAME)

clean:
	make -C libft clean

fclean:
	rm -f $(NAME)
	make -s -C libft fclean

re:	fclean $(NAME)

.PHONY: all clean fclean re