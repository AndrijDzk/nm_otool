/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nm_dispatch_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:32:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 15:47:47 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/fat.h>

#include "ft_nm.h"

void			get_nm_disp_fncs(int (**func_arr)(void*), unsigned int *m)
{
	m[0] = MH_MAGIC;
	func_arr[0] = &handle;
	m[1] = MH_MAGIC_64;
	func_arr[1] = &handle_64;
	m[2] = FAT_MAGIC;
	func_arr[2] = &handle_fat;
	m[3] = FAT_CIGAM;
	func_arr[3] = &handle_fat;
	m[4] = FAT_MAGIC_64;
	func_arr[4] = &handle_fat_64;
	m[5] = FAT_CIGAM_64;
	func_arr[5] = &handle_fat_64;
}
