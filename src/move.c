/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:49:26 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/29 14:25:40 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_go_up(t_main *p)
{
	if (((p->player.x - 1) < p->data.size.y && (p->player.x - 1) >= 0) \
		&& p->data.map[p->player.x - 1][p->player.y] != '1')
	{
		p->player.x -= 1;
		if (p->data.map[p->player.x][p->player.y] == 'C')
		{
			p->collect_count += 1;
			p->data.map[p->player.x][p->player.y] = '0';
		}
		p->move_count++;
		ft_output_util(p, 1, 0);
	}
}

void	ft_go_down(t_main *p)
{
	if (((p->player.x + 1) < p->data.size.y && (p->player.x + 1) >= 0) \
		&& p->data.map[p->player.x + 1][p->player.y] != '1')
	{
		p->player.x += 1;
		if (p->data.map[p->player.x][p->player.y] == 'C')
		{
			p->collect_count += 1;
			p->data.map[p->player.x][p->player.y] = '0';
		}
		p->move_count++;
		ft_output_util(p, -1, 0);
	}
}

void	ft_go_left(t_main *p)
{
	if (((p->player.y - 1) < p->data.size.x && (p->player.y - 1) >= 0) \
		&& p->data.map[p->player.x][p->player.y -1] != '1')
	{
		p->player.y -= 1;
		if (p->data.map[p->player.x][p->player.y] == 'C')
		{
			p->collect_count += 1;
			p->data.map[p->player.x][p->player.y] = '0';
		}
		p->move_count++;
		ft_output_util(p, 0, 1);
	}
}

void	ft_go_right(t_main *p)
{
	if (((p->player.y + 1) < p->data.size.x && (p->player.y + 1) >= 0) \
		&& p->data.map[p->player.x][p->player.y + 1] != '1')
	{
		p->player.y += 1;
		if (p->data.map[p->player.x][p->player.y] == 'C')
		{
			p->collect_count += 1;
			p->data.map[p->player.x][p->player.y] = '0';
		}
		p->move_count++;
		ft_output_util(p, 0, -1);
	}
}

void	check_move(int keycode, t_main *p)
{
	if (keycode == 0 || keycode == 123)
		ft_go_left(p);
	else if (keycode == 2 || keycode == 124)
		ft_go_right(p);
	else if (keycode == 1 || keycode == 125)
		ft_go_down(p);
	else if (keycode == 13 || keycode == 126)
		ft_go_up(p);
}
