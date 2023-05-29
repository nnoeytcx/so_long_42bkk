/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:58:31 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/29 17:43:56 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_check(va_list args, const char c);
size_t	ft_strlenpf(const char *s);
int		ft_putnbr_id(int n);
int		ft_putchar_c(char c);
int		ft_percent(void);
int		ft_putstr_s(char *s);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_lx16(unsigned int n);
int		ft_putnbr_ux16(unsigned int n);
int		ft_putnbr_p(unsigned long n);

#endif