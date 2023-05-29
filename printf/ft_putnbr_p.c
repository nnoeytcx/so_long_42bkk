/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:04:02 by tpoungla          #+#    #+#             */
/*   Updated: 2022/11/09 00:04:02 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(unsigned long n)
{
	unsigned long	num;
	int				i;
	char			c;

	i = 0;
	num = n;
	if (num >= 16)
		i += ft_putnbr_p(num / 16);
	if (num % 16 >= 10)
		c = (num % 16) + 87;
	else
		c = (num % 16) + 48;
	i += write(1, &c, 1);
	return (i);
}
