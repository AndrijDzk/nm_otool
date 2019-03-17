/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_split_condition.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:08:35 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/21 15:11:09 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "flags.h"

char	ft_print_memory_split_condition(size_t const i, const int *flags)
{
	int		col_width;

	if (flags[FLAG_PREC] && flags[FLAG_PREC_VAL] > 0)
		col_width = flags[FLAG_PREC_VAL];
	else
		col_width = 2;
	if ((i % col_width) == 0 && flags[0])
		return (1);
	if ((i % col_width) == 0 && !flags[0])
		return (2);
	return (0);
}
