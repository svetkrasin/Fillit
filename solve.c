/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:26:29 by skrasin           #+#    #+#             */
/*   Updated: 2019/12/16 11:12:22 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_create_map(int n)
{
	char	*map;
	size_t	l;

	l = n * n * sizeof(char);
	if (!(map = (char *)malloc(l)))
		return (NULL);
	map = ft_memset(map, '.', l);
	map[l] = '\0';
	return (map);
}

int		ft_put_tetr(t_tetris node, int n, char *map, int *i)
{
	int j;

	while (map[++*i] != '\0')
	{
		j = -1;
		while (++j < 4)
			if (node.x[0][j] + *i % n > n - 1 || node.x[1][j] + *i / n > n - 1
						|| map[*i + node.x[0][j] + n * node.x[1][j]] != '.')
				break ;
		if (j == 4)
			break ;
	}
	if (map[*i] == '\0')
		return (-1);
	j = -1;
	while (++j < 4)
		map[*i + node.x[0][j] + n * node.x[1][j]] = node.n + 'A';
	return (*i);
}

void	ft_free_c(char *map, t_tetris node, int i, int n)
{
	int j;

	j = -1;
	while (++j < 4)
		map[i + node.x[0][j] + n * node.x[1][j]] = '.';
}

int		ft_print_map(char *map, int n)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		write(1, &map[i], n);
		write(1, "\n", 1);
		i += n;
	}
	free(map);
	return (1);
}

int		ft_backtrack(char *map, t_tetris *node, int n)
{
	int i;
	int l;
	int	k;

	i = -1;
	l = n * n;
	if (node == NULL)
		return (ft_print_map(map, n));
	if ((k = ft_put_tetr(*node, n, map, &i)) > -1)
		while (!ft_backtrack(map, node->next, n) && i < l)
		{
			ft_free_c(map, *node, k, n);
			if ((k = ft_put_tetr(*node, n, map, &i)) == -1)
				return (0);
		}
	else
		return (0);
	return (1);
}
