/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:36 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/26 18:03:35 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

//void	map_size(t_map_status *map, char *ber)
//{
	//int				fd;
	//char		*buffer;

	//fd = open(ber, O_RDONLY);
	//buffer = get_next_line(fd);
//}

t_map_status	get_map(char *ber)
{
	t_map_status	*map;
	int				fd;
	char			*buffer;

	fd = open(ber, O_RDONLY);
	buffer = get_next_line(fd);
}