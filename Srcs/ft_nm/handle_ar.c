/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:58:28 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 15:50:44 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_nm.h"

#include <mach-o/loader.h>
#include <ar.h>

#define LONG_NAME "#1/"

#define HANDLE_AR_CHECK 0
#define HANDLE_AR_NAME_TO_CHECK "ft_int_arr_prefix.o"

char		*get_name(struct ar_hdr *header)
{
	int		i;

	i = 15;
	while (i >= 0 && header->ar_name[i] == ' ')
		i--;
	if (i >= 0)
		return (ft_strsub(header->ar_name, 0, i + 1));
	else
		return (ft_strdup(""));
}

size_t		print_name(struct ar_hdr *header, char const *filename)
{
	char	*name;
	int		i;

	i = 0;
	name = get_name(header);
	if (ft_strbegins(name, LONG_NAME))
	{
		i = ft_atoi(name + ft_strlen(LONG_NAME));
		if (i > 0)
		{
			free(name);
			name = ft_strndup((void*)header + sizeof(*header), (size_t)i);
		}
	}
	if (ft_strcmp(name, "__.SYMDEF SORTED"))
		ft_printf("\n%s(%s):\n", filename, name);
	free(name);
	if (i >= 0)
		return ((size_t)i);
	else
		return (0);
}

int			handle_ar(char *ptr, char const *filename)
{
	struct ar_hdr			*header;
	int						size;
	int						i;
	unsigned int			magic_number;
	size_t					off;

	i = SARMAG;
	header = (void*)ptr + i;
	size = ft_atoi(header->ar_size);
	while (size)
	{
		off = print_name(header, filename);
		magic_number = *(unsigned int*)((void*)ptr + i + sizeof(*header) + off);
		if (magic_number == MH_MAGIC)
			handle((void*)ptr + i + sizeof(*header) + off);
		else if (magic_number == MH_MAGIC_64)
			handle_64((void*)ptr + i + sizeof(*header) + off);
		i += sizeof(*header) + size;
		header = (void*)ptr + i;
		size = ft_atoi(header->ar_size);
	}
	return (0);
}
