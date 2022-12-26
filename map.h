/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:40:27 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/26 18:05:38 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	t_vector	size;
	char		**map;
}	t_map;

typedef struct s_map_status
{
	t_map			map_data;
	unsigned int	no_of_collect;
	unsigned int	collect_count;
	unsigned int	exit_status;
	t_vector		map_size;
	t_vector		player_pos;
}	t_map_status;

# define TRUE 1
# define FALSE 0
# define MAP_DUP_CHAR_ERR "map contains duplicate characters\n"
# define MAP_INVL_CHAR_ERR "map contains invalid character\n"

int	valid_char(char c);
int	valid_component(char *str);

#endif
