/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isqrtc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:27:23 by skrasin           #+#    #+#             */
/*   Updated: 2019/12/16 12:32:23 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	ft_isqrtc(int n)
{
	int x;
	int y;

	y = 1;
	x = n;
	while (x > y)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	if (x * x != n)
		x++;
	return (x);
}

int				ft_abs(int i)
{
	int const mask = i >> (sizeof(int) * 8 - 1);

	return ((i + mask) ^ mask);
}
