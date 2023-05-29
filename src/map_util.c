/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/30 02:29:00 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strlen_no_line(const char *s)
{
	int	i;

	if (*s == '\0' || s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	valid_path_util(t_main *p, int x, int y, int **visited)
{
	if ((x > -1 && y > -1) && (y < p->data.size.x && x < p->data.size.y) \
		&& p->data.map[x][y] != '1' && visited[x][y] == 0)
	{
		visited[x][y] = 1;
		valid_path_util(p, x, y - 1, visited);
		valid_path_util(p, x, y + 1, visited);
		valid_path_util(p, x + 1, y, visited);
		valid_path_util(p, x - 1, y, visited);
	}
}

int	reach_collect(t_main *p, int	**visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->data.size.y)
	{
		j = 0;
		while (j < p->data.size.x)
		{
			if (p->data.map[i][j] == 'C' && visited[i][j] == 0)
			{
				ft_printf("%s%s", ERR, MAP_UNR_COL);
				ft_printf("at %d %d\n", i, j);
				ft_free_vi(visited);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	**check_visit(t_main *p)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * (p->data.size.y + 1));
	while (i < p->data.size.y)
	{
		j = 0;
		visited[i] = (int *)malloc(sizeof(int) * (p->data.size.x));
		while (j < p->data.size.x)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	visited[i] = NULL;
	valid_path_util(p, p->player.x, p->player.y, visited);
	return (visited);
}

int	valid_path(t_main *p, int	**visited)
{
	get_exit_pos(p);
	if (visited[p->exit.x][p->exit.y] == 1)
		return (1);
	else
	{
		ft_printf("%s%s", ERR, MAP_PTH_ERR);
		ft_free_vi(visited);
		return (0);
	}
}
