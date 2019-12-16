/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:14:33 by skrasin           #+#    #+#             */
/*   Updated: 2019/12/16 13:21:02 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*new_tetr(t_tetris **tab)
{
	ssize_t			j;
	static size_t	count = 0;
	static t_tetris	*tail = NULL;
	t_tetris		*new;

	new = (t_tetris*)malloc(sizeof(t_tetris));
	if (!tab || !*tab || !tail)
	{
		tail = new;
		*tab = new;
	}
	else
	{
		tail->next = new;
		tail = tail->next;
	}
	tail->next = NULL;
	j = -1;
	while (++j < 4)
	{
		tail->x[0][j] = -1;
		tail->x[1][j] = -1;
	}
	tail->n = count++;
	return (tail);
}

int			ft_move(t_tetris *tab)
{
	int minx;
	int miny;
	int i;

	minx = tab->x[0][0];
	miny = tab->x[1][0];
	i = 0;
	while (++i < 4)
	{
		if (tab->x[0][i] < minx)
			minx = tab->x[0][i];
		if (tab->x[1][i] < miny)
			miny = tab->x[1][i];
	}
	while (--i > -1)
	{
		tab->x[0][i] -= minx;
		tab->x[1][i] -= miny;
	}
	return (1);
}

int			tetr_add(t_tetris *t, int n)
{
	ssize_t i;
	ssize_t j;
	size_t	connection;

	i = 0;
	while (t->x[0][i] != -1)
		if (i++ > 3)
			return (0);
	t->x[0][i] = n % 5;
	t->x[1][i] = n / 5;
	if (i == 3)
	{
		connection = 0;
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (ft_abs(t->x[0][i] - t->x[0][j])
				+ ft_abs(t->x[1][i] - t->x[1][j]) == 1)
					connection++;
		}
		return ((connection != 6 && connection != 8) ? 0 : ft_move(t));
	}
	return (1);
}

int			validate(char *buff, ssize_t bytesread, t_tetris *tab)
{
	ssize_t i;
	int		num;

	i = 0;
	num = 0;
	while (i < bytesread && buff[i] != '\0')
	{
		if ((i % 5 < 4 && (buff[i] == '.' || buff[i] == '#')) ||
									(i == 20 && buff[i] == '\n'))
		{
			if (buff[i] == '#')
				if (++num && !tetr_add(tab, i))
					return (0);
			i++;
		}
		else if (i % 5 == 4 && (buff[i] == '\n' || buff[i] == '\0'))
			i++;
		else
			return (0);
	}
	if (i < 20 || num != 4)
		return (0);
	return (1);
}

void		list_dell(t_tetris **tab)
{
	t_tetris *temp;

	while (tab && *tab)
	{
		temp = (**tab).next;
		free(*tab);
		*tab = temp;
	}
}
