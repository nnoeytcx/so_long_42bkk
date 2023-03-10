/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/29 04:33:17 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	main(int argc, char **argv)
{
	t_main		p;
	int			*num;

	if (argc != 2)
	{
		printf("%s%s", ERR, WRG_NUM_ARG);
		return (FALSE);
	}
	if (!get_map_size(&p, argv[1]))
		return (FALSE);
	get_map_data(&p, argv[1]);
	num = valid_component(&p, num);
	if (num[5] == 0)
	{
		printf("%s%s", ERR, MAP_INVL_CHAR_ERR);
		return (FALSE);
	}
	if (!com_num_check(&p, num))
		return (FALSE);
	p.exit_status = 0;
	p.collect_count = 0;
	get_player_pos(&p);
	if (!valid_wall(&p))
		return (FALSE);
	return (TRUE);
}
