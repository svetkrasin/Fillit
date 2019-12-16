/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:48:40 by iklimov           #+#    #+#             */
/*   Updated: 2019/12/16 11:14:59 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <sys/stat.h>

typedef struct		s_tetris
{
	int				x[2][4];
	int				n;
	struct s_tetris	*next;
}					t_tetris;

void				error(int i);
t_tetris			*reader(int fd, int *n);
unsigned int		ft_isqrtc(int n);
void				ft_solve(t_tetris *node, int n);
t_tetris			*new_tetr(t_tetris **tab);
int					ft_move(t_tetris *tab);
int					tetr_add(t_tetris *t, int n);
int					validate(char *buff, int bytesread, t_tetris *tab);
void				list_dell(t_tetris **tab);
char				*ft_create_map(int n);
int					ft_put_tetr(t_tetris node, int n, char *map, int *i);
void				ft_free_c(char *map, t_tetris node, int i, int n);
int					ft_print_map(char *map, int n);
int					ft_backtrack(char *map, t_tetris *node, int n);
int					ft_abs(int i);

#endif
