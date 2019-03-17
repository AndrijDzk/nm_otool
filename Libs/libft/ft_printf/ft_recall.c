/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:02:36 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/11 15:12:34 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_int_recall(va_list par, const int *flags)
{
	t_fp	int_rec_funcs[6];

	int_rec_funcs[0] = &ft_put_ascii;
	int_rec_funcs[1] = &ft_put_short;
	int_rec_funcs[2] = &ft_put_long_long;
	int_rec_funcs[3] = &ft_put_long;
	int_rec_funcs[4] = &ft_put_intmax_t;
	int_rec_funcs[5] = int_rec_funcs[4];
	return (int_rec_funcs[flags[9] - 1](par, flags));
}
