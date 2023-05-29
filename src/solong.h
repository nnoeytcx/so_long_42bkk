/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:40:27 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/30 03:51:29 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
//# include <stdlib.h>

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

typedef struct s_program
{
	void	*mlx;
	void	*mlx_win;
}	t_pro;

typedef struct s_main
{
	t_map		data;
	int			no_of_collect;
	int			collect_count;
	int			exit_status;
	int			move_count;
	t_vector	player;
	t_vector	exit;
	t_pro		pro;
}	t_main;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

# define ERR "Error\n"
# define MAP_DUP_CHAR_ERR "map contains duplicate characters (exit/start)\n"
# define MAP_INVL_CHAR_ERR "map contains invalid character\n"
# define MAP_NOT_REC_ERR "map doesn't be in rectengular shape\n"
# define WRG_NUM_ARG "wrong number of arguments\n"
# define MAP_START_EXIT_ERR "missing the starting position or exit\n"
# define MAP_COLLECTIBLES_ERR "collectible is not found\n"
# define MAP_WALLS_ERR "Map must be surrounded by walls\n"
# define MAP_PTH_ERR "can't reach the exit\n"
# define MAP_FLE_ERR "map file not found\n"
# define MAP_UNR_COL "can't reach collectable\n"
# define MAP_NAME_BER "map's name didn't ends with '.ber\n"

int		valid_char(char c);
int		*valid_component(t_main *p, int *num);
int		valid_wall(t_main *p);
int		get_map_size(t_main *p, char *str);
void	get_map_data(t_main *p, char *str);
int		*init_array(int *num, int len);
int		com_num_check(t_main *p, int *num);
void	get_player_pos(t_main *p);
void	get_exit_pos(t_main *p);
int		check_list(t_main *p, int *num);
int		ft_strlen_no_line(const char *s);
int		valid_path(t_main *p, int	**visited);
void	valid_path_util(t_main *p, int x, int y, int **visited);
void	windowinit(t_main	*p);
int		mlx_close(void *ptr);
int		key_hook(int keycode, void *arg);
void	*ft_ftoi(void *mlx, char *path);
void	ft_output(t_main	*p);
void	check_move(int keycode, t_main *p);
int		reach_collect(t_main *p, int	**visited);
int		**check_visit(t_main *p);
void	ft_output_util(t_main *p, int n, int m);
void	ft_free_map(t_main *p);
void	ft_free_vi(int **visited);

#endif
