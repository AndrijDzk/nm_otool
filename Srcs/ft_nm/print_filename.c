/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:49:20 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/03 17:52:35 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_filename(char **argv, int i)
{
	if (i < 0)
		ft_printf("\n%s:\n", "./a.out");
	else
		ft_printf("\n%s:\n", argv[i]);
}
