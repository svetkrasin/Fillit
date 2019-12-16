/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iklimov <iklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:17:43 by iklimov           #+#    #+#             */
/*   Updated: 2019/12/13 12:45:47 by iklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int i)
{
	char const		*err_msg[3] = {"Nothing wrong\n",
							"usage:\t./fillit\tsource_file\n", "error\n"};

	ft_putstr(err_msg[i]);
}
