/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:23:25 by tpoungla          #+#    #+#             */
/*   Updated: 2022/11/07 11:23:25 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_id(int n)
{
	char	c;
	long	num;
	int		i;

	i = 0;
	num = (long)n;
	if (num < 0)
	{
		i += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		i += ft_putnbr_id(num / 10);
	c = (num % 10) + '0';
	i += write(1, &c, 1);
	return (i);
}
