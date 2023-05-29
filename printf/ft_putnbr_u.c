/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:29:21 by tpoungla          #+#    #+#             */
/*   Updated: 2022/11/08 00:29:21 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	char			c;
	unsigned long	num;
	int				i;

	i = 0;
	num = (long)n;
	if (num >= 10)
		i += ft_putnbr_id(num / 10);
	c = (num % 10) + '0';
	i += write(1, &c, 1);
	return (i);
}
