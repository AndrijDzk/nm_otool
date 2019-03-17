/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fp_arr_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 10:54:13 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/10 12:57:30 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_fp_arr_init_floating_point_funcs(t_fp *arr)
{
	arr[17] = &ft_put_float;
	arr[18] = arr[17];
	arr[19] = arr[17];
	arr[20] = arr[17];
}

t_fp	*ft_fp_arr_init(void)
{
	t_fp	*res;

	res = (t_fp*)malloc(sizeof(*res) * 21);
	res[0] = &ft_put_char;
	res[1] = &ft_put_wchar;
	res[2] = &ft_put_str;
	res[3] = &ft_put_wstr;
	res[4] = &ft_put_pointer;
	res[5] = &ft_put_int;
	res[6] = &ft_put_long;
	res[7] = res[5];
	res[8] = &ft_put_oint;
	res[9] = res[8];
	res[10] = &ft_put_uint;
	res[11] = res[10];
	res[12] = &ft_put_hint;
	res[13] = res[12];
	res[14] = &ft_put_int_arr;
	res[15] = &ft_put_tab;
	res[16] = &ft_put_memory;
	ft_fp_arr_init_floating_point_funcs(res);
	return (res);
}
