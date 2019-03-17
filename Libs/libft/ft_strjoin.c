/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:10:49 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/05 10:54:56 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (0);
	else
	{
		if (!(res = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		j = 0;
		i = 0;
		if (s1)
			while (s1[i])
				res[j++] = s1[i++];
		i = 0;
		if (s2)
			while (s2[i])
				res[j++] = s2[i++];
		res[j] = '\0';
		return (res);
	}
}
