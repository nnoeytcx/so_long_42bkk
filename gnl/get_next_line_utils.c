/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:57:31 by tpoungla          #+#    #+#             */
/*   Updated: 2023/05/29 17:45:01 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *b, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len)
	{
		*str = '\0';
		str++;
		len--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (void *)malloc(count * size);
	if (!p || count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

int	ft_strlenmo(const char *s)
{
	int	i;

	if (*s == '\0' || s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*res;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlenmo(s1) + ft_strlenmo(s2) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char) c)
		str++;
	if (*str == (char) c)
		return ((char *)str);
	return (0);
}
