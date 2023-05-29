/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:40:27 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/30 01:12:36 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "solong.h"

int	mlx_close(void *ptr)
{
	(void) ptr;
	exit (0);
	return (0);
}

void	*ft_ftoi(void *mlx, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	return (img);
}

void	windowinit(t_main	*p)
{
	p->pro.mlx = mlx_init();
	p->pro.mlx_win = mlx_new_window(p->pro.mlx, p->data.size.x \
	* 32, p->data.size.y * 32, "Hello my so_long world!");
	ft_output(p);
	mlx_hook(p->pro.mlx_win, 17, 1L << 0, mlx_close, NULL);
	mlx_key_hook(p->pro.mlx_win, key_hook, p);
	mlx_loop(p->pro.mlx);
}
