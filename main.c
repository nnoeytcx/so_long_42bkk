/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/27 20:12:53 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	main(int argc, char **argv)
{
	t_main		p;
	int			i;

	i = 0;
	get_map_size(&p, argv[1]);
	printf("%d %d\n", p.data.size.x, p.data.size.y);
	get_map_data(&p, argv[1]);
	while (p.data.map[i])
	{
		printf("%s", p.data.map[i]);
		i++;
	} 
	return (0);
}
