/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isqrtc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:27:23 by iklimov           #+#    #+#             */
/*   Updated: 2019/12/16 11:16:44 by svet             ###   ########.fr       */
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

int	ft_abs(int i)
{
	int const mask = i >> (sizeof(int) * 8 - 1);
	return ((i + mask) ^ mask);
}
