/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 09:10:45 by adzikovs          #+#    #+#             */
/*   Updated: 2016/11/29 16:02:57 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	if (src)
	{
		i = 0;
		while (src[i])
			i++;
		dest = (char*)malloc(sizeof(*src) * (i + 1));
		i = 0;
		if (dest)
		{
			while (src[i])
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
		return (dest);
	}
	else
		return (0);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (n == 0)
		return (ft_strdup(""));
	if (src)
	{
		if ((size = ft_strlen(src)) > n)
			size = n;
		dst = (char*)malloc(sizeof(*src) * (size + 1));
		if (dst == NULL)
			return (NULL);
		i = 0;
		while (src[i] && i < size)
		{
			dst[i] = src[i];
			i++;
			n--;
		}
		dst[size] = '\0';
		return (dst);
	}
	else
		return (NULL);
}
