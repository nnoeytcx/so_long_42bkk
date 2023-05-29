/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/30 03:51:18 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "solong.h"

void	ft_free_vi(int **visited)
{
	int	i;

	i = 0;
	ft_printf("STARTFREEvisit\n");
	while (visited[i])
	{
		free(visited[i]);
		i++;
	}
	ft_printf("FREEEDvisit\n");
	free(visited);
}

void	ft_free_map(t_main *p)
{
	int		i;

	i = 0;
	ft_printf("STARTFREEmap\n");
	while (p->data.map[i])
	{
		free(p->data.map[i]);
		i++;
	}
	ft_printf("FREEEDmap\n");
	free(p->data.map);
}

int	check_list(t_main *p, int *num)
{
	int	**visited;

	num = valid_component(p, num);
	if (num[5] == 0)
	{
		ft_printf("%s%s", ERR, MAP_INVL_CHAR_ERR);
		return (0);
	}
	if (!com_num_check(p, num))
		return (0);
	p->exit_status = 0;
	p->collect_count = 0;
	p->move_count = 0;
	get_player_pos(p);
	if (!valid_wall(p))
		return (0);
	visited = check_visit(p);
	if (!valid_path(p, visited) || !reach_collect(p, visited))
		return (0);
	ft_free_vi(visited);
	return (1);
}

int	main(int argc, char **argv)
{
	t_main		p;
	int			*num;

	if (argc != 2)
		return (ft_printf("%s%s", ERR, WRG_NUM_ARG), 0);
	if (ft_strrchr(argv[1], '.') == NULL)
		return (ft_printf("%s%s", ERR, MAP_NAME_BER), 0);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5))
		return (ft_printf("%s%s", ERR, MAP_NAME_BER), 0);
	if (!get_map_size(&p, argv[1]))
		return (0);
	get_map_data(&p, argv[1]);
	num = malloc(sizeof(int) * 6);
	num = init_array(num, 6);
	if (check_list(&p, num))
	{
		ft_printf("NO ERROR\n");
		ft_printf("FREEEDnum\n");
		free(num);
		windowinit(&p);
	}
	ft_free_map(&p);
	free(num);
	ft_printf("FREEEDnum\n");
}
