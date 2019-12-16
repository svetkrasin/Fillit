/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:45:32 by skrasin           #+#    #+#             */
/*   Updated: 2019/12/16 13:13:22 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*reader(int fd, size_t *n)
{
	ssize_t		len;
	char		buff[22];
	t_tetris	*tab;
	t_tetris	*tail;

	tab = NULL;
	len = 21;
	while (len == 21)
	{
		len = read(fd, buff, 21);
		buff[len] = '\0';
		tail = new_tetr(&tab);
		if (validate(buff, len, tail) == 0)
		{
			list_dell(&tab);
			return (NULL);
		}
		(*n)++;
	}
	return (tab);
}

void		ft_solve(t_tetris *node, size_t n)
{
	char *map;

	map = ft_create_map(n);
	while (!ft_backtrack(map, node, n))
	{
		free(map);
		map = ft_create_map(++n);
	}
}

int			main(int argc, char **argv)
{
	int			fd;
	size_t		n;
	t_tetris	*tab;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error(2);
		n = 0;
		tab = reader(fd, &n);
		if (tab)
		{
			if (n > 26)
				error(2);
			close(fd);
			ft_solve(tab, ft_isqrtc(n * 4));
			list_dell(&tab);
		}
		else
			error(2);
	}
	else
		error(1);
	return (0);
}
