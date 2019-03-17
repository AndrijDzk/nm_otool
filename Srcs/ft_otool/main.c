/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:45:41 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 16:52:11 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mach-o/loader.h>
#include <mach-o/fat.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <ar.h>

#define ARCH32 32
#define ARCH64 64

#include "libft.h"

#include "ft_otool.h"

int		is_fat(unsigned int magic_number)
{
	if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		return (ARCH32);
	else if (magic_number == FAT_MAGIC_64 || magic_number == FAT_CIGAM_64)
		return (ARCH64);
	else
		return (0);
}

int		is_mach_o(unsigned int magic_number)
{
	if (magic_number == MH_MAGIC)
		return (ARCH32);
	else if (magic_number == MH_MAGIC_64)
		return (ARCH64);
	else
		return (0);
}

void	print_filename(char *filename)
{
	ft_printf("%s:\n", filename);
	ft_printf("Contents of (__TEXT,__text) section\n");
}

int		otool(char *ptr, int argc, char **argv, int i)
{
	unsigned int	magic_number;

	if (i >= argc || i < 1)
		return (-1);
	magic_number = *(unsigned int*)ptr;
	if (is_mach_o(magic_number))
	{
		print_filename(argv[i]);
		if (is_mach_o(magic_number) == ARCH32)
			return (handle(ptr));
		else
			return (handle_64(ptr));
	}
	else if (is_fat(magic_number))
	{
		print_filename(argv[i]);
		if (is_fat(magic_number) == ARCH32)
			return (handle_fat(ptr));
		else
			return (handle_fat_64(ptr));
	}
	else if (magic_number == *(unsigned int*)ARMAG)
		return (handle_ar(ptr, argv[i]));
	else
		return (not_an_object_file(argc, argv, i));
}

int		main(int argc, char **argv)
{
	int				i;
	int				fd;
	struct stat		buff;
	char			*ptr;

	set_g_arch();
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0 || fstat(fd, &buff) < 0)
				return (no_such_file_error(argc, argv, i));
			ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
			if (ptr == MAP_FAILED || buff.st_size < (long)sizeof(unsigned int))
				not_an_object_file(argc, argv, i);
			otool(ptr, argc, argv, i);
			i++;
		}
	}
	else
		ft_printf("Usage: %s <object_file> ...\n", argv[0]);
	return (0);
}
