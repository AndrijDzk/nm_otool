/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_g_arch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:33:00 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 14:49:58 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_arch;

void	set_g_arch(void)
{
	if (sizeof(void*) == 8)
		g_arch = 64;
	else
		g_arch = 32;
}
