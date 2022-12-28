/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:40:27 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/27 20:08:45 by tpoungla         ###   ########.fr       */
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

typedef struct s_main
{
	t_map			data;
	unsigned int	no_of_collect;
	unsigned int	collect_count;
	unsigned int	exit_status;
	t_vector		player;
}	t_main;

# define TRUE 1
# define FALSE 0
# define MAP_DUP_CHAR_ERR "map contains duplicate characters\n"
# define MAP_INVL_CHAR_ERR "map contains invalid character\n"

int		valid_char(char c);
int		valid_component(char **str);
void	get_map_size(t_main *p, char *str);
void	get_map_data(t_main *p, char *str);

#endif
