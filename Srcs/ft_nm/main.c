/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:04:51 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/18 12:35:00 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <mach-o/loader.h>
#include <mach-o/fat.h>
#include <ar.h>

#include "ft_nm.h"

#include "libft.h"

int		nm(char *ptr, int argc, char **argv, int i)
{
	int					(*d_arr[NM_DISP_FUNCS_AM])(void*);
	unsigned int		magic_arr[NM_DISP_FUNCS_AM];
	size_t				j;

	get_nm_disp_fncs(d_arr, magic_arr);
	if (*(unsigned int*)ptr == *(unsigned int*)ARMAG)
	{
		if (i < 0)
			return (handle_ar(ptr, "./a.out"));
		else
			return (handle_ar(ptr, argv[i]));
	}
	j = 0;
	while (j < NM_DISP_FUNCS_AM)
	{
		if (*(unsigned int*)ptr == magic_arr[j])
		{
			if (argc > 2 && j < 2)
				print_filename(argv, i);
			return ((*(d_arr[j]))(ptr));
		}
		j++;
	}
	return (not_an_object_file(argc, argv, i));
}

int		open_a_out(int argc, char **argv)
{
	int				fd;
	struct stat		buff;
	char			*ptr;

	fd = open("./a.out", O_RDONLY);
	if (fd < 0 || fstat(fd, &buff) < 0)
		return (no_such_file_error(argc, argv, -1));
	ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ptr == MAP_FAILED)
		return (not_an_object_file(argc, argv, -1));
	nm(ptr, argc, argv, -1);
	return (0);
}

void	*open_file(int argc, char **argv, int i)
{
	int				fd;
	struct stat		buff;
	void			*ptr;

	fd = open(argv[i], O_RDONLY);
	if (fd < 0 || fstat(fd, &buff) < 0)
	{
		no_such_file_error(argc, argv, i);
		return (NULL);
	}
	ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ptr == MAP_FAILED || buff.st_size < (long)sizeof(unsigned int))
	{
		not_an_object_file(argc, argv, i);
		return (NULL);
	}
	return (ptr);
}

int		main(int argc, char **argv)
{
	int				i;
	char			*ptr;

	set_g_arch();
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if ((ptr = open_file(argc, argv, i)))
				nm(ptr, argc, argv, i);
			i++;
		}
		return (0);
	}
	else
		return (open_a_out(argc, argv));
}
