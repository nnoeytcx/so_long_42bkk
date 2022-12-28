/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:36 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/29 04:41:17 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_player_pos(t_main *p)
{
	int		i;
	int		j;

	i = 0;
	while (p->data.map[i])
	{
		j = 0;
		while (p->data.map[i][j] && p->data.map[i][j] != '\n')
		{
			if (p->data.map[i][j] == 'P')
			{
				p->player.x = i;
				p->player.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	get_map_size(t_main	*p, char *str)
{
	int		fd;
	char	*buffer;
	int		height;
	int		width;

	height = 0;
	fd = open(str, O_RDONLY);
	buffer = get_next_line(fd);
	width = ft_strlen_no_line(buffer);
	while (buffer != NULL)
	{
		height++;
		if (width != ft_strlen_no_line(buffer))
		{
			printf("%s%s", ERR, MAP_NOT_REC_ERR);
			return (FALSE);
		}
		width = ft_strlen_no_line(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	p->data.size.y = height;
	p->data.size.x = width;
	return (TRUE);
}

void	get_map_data(t_main *p, char *str)
{
	int		fd;
	char	*buffer;
	int		i;

	fd = open(str, O_RDONLY);
	buffer = get_next_line(fd);
	p->data.map = malloc(sizeof(char *) * (p->data.size.y + 1));
	i = 0;
	while (buffer != NULL)
	{
		p->data.map[i] = buffer;
		i++;
		buffer = get_next_line(fd);
	}
	close(fd);
}
