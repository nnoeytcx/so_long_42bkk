/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ux16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:56:37 by tpoungla          #+#    #+#             */
/*   Updated: 2022/11/08 23:56:37 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ux16(unsigned int n)
{
	unsigned int	num;
	int				i;
	char			c;

	i = 0;
	num = n;
	if (num >= 16)
		i += ft_putnbr_ux16(num / 16);
	if (num % 16 >= 10)
		c = (num % 16) + 55;
	else
		c = (num % 16) + 48;
	i += write(1, &c, 1);
	return (i);
}
