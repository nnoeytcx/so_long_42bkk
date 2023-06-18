/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2023/06/19 00:26:43 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "../mlx/mlx.h"

int	key_hook(int keycode, void *arg)
{
	t_main	*p;

	p = (t_main *)arg;
	if (keycode == 53)
	{
		ft_free_map(p);
		exit(0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 \
		|| keycode == 123 || keycode == 124 || keycode == 125 \
		|| keycode == 126)
		check_move(keycode, p);
	return (0);
}

void	ft_put_pic(t_main *p, char *pic, int n, int m)
{
	mlx_put_image_to_window(p->pro.mlx, p->pro.mlx_win, \
	ft_ftoi(p->pro.mlx, pic), m, n);
}

void	ft_output(t_main *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < p->data.size.y)
	{
		j = 0;
		while (j < p->data.size.x)
		{
			if (p->data.map[i][j] == '1')
				ft_put_pic(p, "pic/watertile.xpm", i * 32, j * 32);
			else if (p->data.map[i][j] == '0')
				ft_put_pic(p, "pic/grass.xpm", i * 32, j * 32);
			else if (p->data.map[i][j] == 'C')
				ft_put_pic(p, "pic/muuk.xpm", i * 32, j * 32);
			else if (p->data.map[i][j] == 'E')
				ft_put_pic(p, "pic/close.xpm", i * 32, j * 32);
			if (i == p->player.x && j == p->player.y)
				ft_put_pic(p, "pic/player.xpm", i * 32, j * 32);
			j++;
		}
		i++;
	}
}

void	exit_con(t_main *p)
{
	if ((p->player.x == p->exit.x && p->player.y == p->exit.y) \
	&& p->collect_count == p->no_of_collect)
	{
		ft_free_map(p);
		exit(0);
	}
}

void	ft_output_util(t_main *p, int n, int m)
{
	int		i;
	int		j;

	i = 0;
	while (i < p->data.size.y)
	{
		j = 0;
		while (j < p->data.size.x)
		{
			if (p->data.map[i][j] == 'E')
				ft_putexit(p, i, j);
			else if (i == p->player.x + n && j == p->player.y + m)
				ft_put_pic(p, "pic/grass.xpm", i * 32, j * 32);
			if (i == p->player.x && j == p->player.y)
				ft_put_pic(p, "pic/player.xpm", i * 32, j * 32);
			j++;
		}
		i++;
	}
	exit_con(p);
	ft_printf("move count    : %d\n", p->move_count);
	ft_printf("collect_count : %d\n", p->collect_count);
}
