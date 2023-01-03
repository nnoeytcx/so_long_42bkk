/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2023/01/03 16:45:03 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
	if (p->data.map[x][y] != '1' && visited[x][y] == 0 &&
	(x > -1 && y > -1) && (y < p->data.size.x && x < p->data.size.y))
	{
		visited[x][y] = 1;
		valid_path_util(p, x, y - 1, visited);
		valid_path_util(p, x, y + 1, visited);
		valid_path_util(p, x + 1, y, visited);
		valid_path_util(p, x - 1, y, visited);
	}
}

int	valid_path(t_main *p)
{
	int	x;
	int	y;
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * (p->data.size.y));
	while (i < p->data.size.y)
	{
		visited[i] = (int *)malloc(sizeof(int) * (p->data.size.x));
		i++;
	}
	valid_path_util(p, p->player.x, p->player.y, visited);
	get_exit_pos(p);
	if (visited[p->exit.x][p->exit.y] == 1)
		return (1);
	else
	{
		printf("%s%s", ERR, MAP_PTH_ERR);
		return (0);
	}
}
