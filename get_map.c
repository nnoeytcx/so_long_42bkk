/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:36 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/27 20:11:44 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_map_size(t_main	*p, char *str)
{
	int		fd;
	char	*buffer;
	int		height;
	int		width;

	height = 0;
	fd = open(str, O_RDONLY);
	buffer = get_next_line(fd);
	width = ft_strlen(buffer);
	while (buffer != NULL)
	{
		height++;
		if (width != ft_strlen(buffer))
		{
			//send error
			break ;
		}
		width = ft_strlen(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	p->data.size.y = height;
	p->data.size.x = width - 1;
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