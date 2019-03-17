/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:43:04 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/05 12:04:03 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_wstrlen(const wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_wcharlen(const wchar_t *c)
{
	int		i;

	i = 0;
	while (((char*)c)[i] && i < (int)sizeof(wchar_t))
		i++;
	return (i);
}
