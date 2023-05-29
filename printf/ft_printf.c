/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:55:35 by tpoungla          #+#    #+#             */
/*   Updated: 2022/11/07 09:55:35 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, const char c)
{
	if (c == 'c')
		return (ft_putchar_c(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_s(va_arg(args, char *)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_p(va_arg(args, unsigned long)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_id(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_lx16(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_putnbr_ux16(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_percent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (!*str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_check(args, *(str + 1));
			str++;
		}
		else
			i += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (i);
}
