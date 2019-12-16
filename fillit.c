/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:45:32 by iklimov           #+#    #+#             */
/*   Updated: 2019/12/16 11:13:41 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*reader(int fd, int *n)
{
	int			bytesread;
	char		buff[22];
	t_tetris	*tab;
	t_tetris	*tail;

	tab = NULL;
	bytesread = 21;
	while (bytesread == 21)
	{
		bytesread = read(fd, buff, 21);
		buff[bytesread] = '\0';
		tail = new_tetr(&tab);
		if ((++(*n)) && validate(buff, bytesread, tail) == 0)
		{
			list_dell(&tab);
			return (NULL);
		}
	}
	return (tab);
}

void		ft_solve(t_tetris *node, int n)
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
	int			n;
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
