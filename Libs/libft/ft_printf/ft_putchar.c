/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:17:39 by adzikovs          #+#    #+#             */
/*   Updated: 2017/02/01 13:57:49 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "libprintf.h"

int		ft_putchar(char c, const int *flags)
{
	return (write(flags[FLAGS_AM], &c, 1));
}
