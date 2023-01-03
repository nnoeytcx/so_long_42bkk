/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2023/01/03 16:31:24 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	valid_char(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (2);
	else if (c == 'C')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'P')
		return (5);
	else
		return (FALSE);
}

int	*init_array(int *num, int len)
{
	int		i;

	num = malloc(sizeof(int) * (len));
	i = 0;
	while (i < len)
	{
		num[i] = 0;
		i++;
	}
	return (num);
}

int	*valid_component(t_main *p, int *num)
{
	char	*chr;
	int		*count;
	int		i;
	int		j;

	chr = "01CEP";
	i = 0;
	count = init_array(count, 6);
	count[5] = 1;
	while (p->data.map[i])
	{
		j = 0;
		while (p->data.map[i][j] && p->data.map[i][j] != '\n')
		{
			if (valid_char(p->data.map[i][j]) > 0)
				count[valid_char(p->data.map[i][j]) - 1]++;
			else
				count[5] = 0;
			j++;
		}
		i++;
	}
	return (count);
}

int	com_num_check(t_main *p, int *num)
{
	if (num[2] < 1)
	{
		printf("%s%s", ERR, MAP_COLLECTIBLES_ERR);
		return (FALSE);
	}
	if (num[3] == 0 || num[4] == 0)
	{
		printf("%s%s", ERR, MAP_START_EXIT_ERR);
		return (FALSE);
	}
	if (num[3] > 1 || num[4] > 1)
	{
		printf("%s%s", ERR, MAP_DUP_CHAR_ERR);
		return (FALSE);
	}
	p->no_of_collect = num[2];
	return (TRUE);
}

int	valid_wall(t_main *p)
{
	int		i;

	i = 0;
	while (i < p->data.size.x)
	{
		if (p->data.map[0][i] != '1' ||
			p->data.map[p->data.size.y - 1][i] != '1')
		{
			printf("%s%s", ERR, MAP_WALLS_ERR);
			return (FALSE);
		}
		i++;
	}
	i = 0;
	while (i < p->data.size.y)
	{
		if (p->data.map[i][0] != '1' ||
			p->data.map[i][p->data.size.x - 1] != '1')
		{
			printf("%s%s", ERR, MAP_WALLS_ERR);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
