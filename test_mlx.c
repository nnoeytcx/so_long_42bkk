/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:40:27 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/26 13:24:07 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int     w;
    int     h;
    int i;
    int j;

    i = 0;
    j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 640, "Hello world!");
    img.img = mlx_xpm_file_to_image(mlx, "grass.xpm", &w, &h);
	// img.img = mlx_new_image(mlx, 960, 540);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    while (i<960)
    {
        while (j<640)
        {
            mlx_put_image_to_window(mlx, mlx_win, img.img, i, j);
            j += 32;
        }
        i += 32;
        j = 0;
    }
	mlx_loop(mlx);
}
