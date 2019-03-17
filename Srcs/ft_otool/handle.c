/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 10:43:21 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/03 16:21:53 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>

#include "ft_otool.h"
#include "libft.h"

int		print_section(void *ptr, struct section *sect)
{
	uint32_t	i;
	uint32_t	addr;
	void		*val;

	i = 0;
	while (i < sect->size)
	{
		addr = sect->addr + i;
		val = ptr + sect->offset + i;
		if (sect->size - i >= 16)
			ft_printf("%08llx\t%16.1m", addr, val);
		else
			ft_printf("%08llx\t%*.1m", addr, sect->size - i, val);
		i += 16;
	}
	return (0);
}

int		print_segment(void *ptr, struct segment_command *seg)
{
	uint32_t			i;
	struct section		*sections_arr;
	char				*sectname;

	sections_arr = (struct section*)((void*)seg + sizeof(*seg));
	i = 0;
	while (i < seg->nsects)
	{
		sectname = sections_arr[i].sectname;
		if (ft_strcmp(sectname, "__text") == 0)
			print_section(ptr, sections_arr + i);
		i++;
	}
	return (0);
}

int		handle(void *ptr)
{
	int							cmds_am;
	struct load_command			*lc;

	cmds_am = ((struct mach_header*)ptr)->ncmds;
	lc = ptr + sizeof(struct mach_header);
	while (cmds_am > 0)
	{
		if (lc->cmd == LC_SEGMENT)
			print_segment(ptr, (struct segment_command*)lc);
		if (lc->cmd == LC_SEGMENT_64)
			print_segment_64(ptr, (struct segment_command_64*)lc);
		lc = (void*)lc + lc->cmdsize;
		cmds_am--;
	}
	return (0);
}
