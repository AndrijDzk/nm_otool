/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:07:55 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/07 17:43:49 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		ft_strbegins(const char *str, char const *start)
{
	size_t		i;

	if (str == NULL || start == NULL)
		return (0);
	i = 0;
	while (start[i])
	{
		if (str[i] != start[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_strdiff(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
