/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:39:19 by tpoungla          #+#    #+#             */
/*   Updated: 2022/12/20 16:43:26 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (TRUE);
	else
		return (FALSE);
}

int	valid_component(char *str)
{
	int	p;
	int	e;
	int	i;

	i = 0;
	p = 0;
	e = 0;
	while (str[i])
	{
		if (valid_char(str[i]))
		{
			if (str[i] == 'E')
				e++;
			else if (str[i] == 'P')
				p++;
		}
		else
			return (0);
		if (e > 1 || p > 1)
			return (0);
		i++;
	}
}

//char	*ft_strchr(const char *str, int c)