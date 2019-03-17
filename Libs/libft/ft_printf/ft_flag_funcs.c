/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:27:07 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/12 11:27:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_flag_hash(int *flags)
{
	flags[0] = 1;
}

void	ft_flag_zero(int *flags)
{
	if (flags[2] == 0)
		flags[1] = 1;
}

void	ft_flag_minus(int *flags)
{
	flags[1] = 0;
	flags[2] = 1;
}

void	ft_flag_plus(int *flags)
{
	flags[4] = 0;
	flags[3] = 1;
}

void	ft_flag_space(int *flags)
{
	if (flags[3] == 0)
		flags[4] = 1;
}
