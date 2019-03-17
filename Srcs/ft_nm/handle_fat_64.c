/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat_64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 18:02:49 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 16:04:03 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/fat.h>
#include <ar.h>

#include "libft.h"
#include "ft_nm.h"

static unsigned long	get_big_endian_int(void *ptr, size_t size)
{
	unsigned long		res;
	size_t				i;

	if (size > sizeof(res))
		return (0);
	res = 0;
	i = 0;
	while (i < size)
	{
		res = (res << 8) + *((unsigned char*)ptr + i);
		i++;
	}
	return (res);
}

uint32_t				get_nfat_arch_64(void *ptr)
{
	struct fat_header		*header;
	size_t					size;

	header = ptr;
	size = sizeof(header->nfat_arch);
	if (header->magic == FAT_MAGIC)
		return (header->nfat_arch);
	else if (header->magic == FAT_CIGAM)
		return ((uint32_t)get_big_endian_int(&(header->nfat_arch), size));
	else
		return (0);
}

void					*get_file_ptr_64(void *ptr, size_t i)
{
	struct fat_header		*header;
	struct fat_arch_64		*f_hdr;
	uint64_t				offset;
	size_t					size;

	header = ptr;
	f_hdr = ptr + sizeof(*header) + sizeof(*f_hdr) * i;
	size = sizeof(offset);
	if (header->magic == FAT_MAGIC)
	{
		offset = f_hdr->offset;
		return (ptr + offset);
	}
	else if (header->magic == FAT_CIGAM)
	{
		offset = (uint64_t)get_big_endian_int(&(f_hdr->offset), size);
		return (ptr + offset);
	}
	else
		return (NULL);
}

int						handle_fat_64(void *ptr)
{
	uint32_t				nfat_arch;
	size_t					i;
	void					*file_ptr;
	unsigned int			magic_number;

	nfat_arch = get_nfat_arch_64(ptr);
	i = 0;
	while (i < nfat_arch)
	{
		file_ptr = get_file_ptr_64(ptr, i);
		magic_number = *(unsigned int*)file_ptr;
		if (magic_number == MH_MAGIC && g_arch == 32)
			handle(file_ptr);
		else if (magic_number == MH_MAGIC_64 && g_arch == 64)
			handle_64(file_ptr);
		i++;
	}
	return (0);
}
