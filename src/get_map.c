/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:36 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/30 03:54:27 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
				p->data.map[i][j] = '0';
				p->player.x = i;
				p->player.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	get_exit_pos(t_main *p)
{
	int		i;
	int		j;

	i = 0;
	while (p->data.map[i])
	{
		j = 0;
		while (p->data.map[i][j] && p->data.map[i][j] != '\n')
		{
			if (p->data.map[i][j] == 'E')
			{
				p->exit.x = i;
				p->exit.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	close_fd(int fd, t_main *p, int h, int w)
{
	close(fd);
	p->data.size.y = h;
	p->data.size.x = w;
}

int	get_map_size(t_main	*p, char *str)
{
	int		fd;
	char	*buffer;
	int		height;
	int		width;

	height = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("%s%s", ERR, MAP_FLE_ERR), 0);
	buffer = get_next_line(fd);
	width = ft_strlen_no_line(buffer);
	while (buffer != NULL)
	{
		height++;
		if (width != ft_strlen_no_line(buffer))
		{
			free(buffer);
			return (ft_printf("%s%s", ERR, MAP_NOT_REC_ERR), 0);
		}
		width = ft_strlen_no_line(buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close_fd(fd, p, height, width);
	return (1);
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
	p->data.map[i] = NULL;
	close(fd);
}
