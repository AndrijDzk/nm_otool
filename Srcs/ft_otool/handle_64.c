/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 10:43:21 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/22 10:45:51 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>

#include "libft.h"
#include "ft_otool.h"

int		print_section_64(void *ptr, struct section_64 *sect)
{
	uint64_t	i;
	uint64_t	addr;
	void		*val;

	i = 0;
	while (i < sect->size)
	{
		addr = sect->addr + i;
		val = ptr + sect->offset + i;
		if (sect->size - i >= 16)
			ft_printf("%016llx\t%16.1m", addr, val);
		else
			ft_printf("%016llx\t%*.1m", addr, sect->size - i, val);
		i += 16;
	}
	return (0);
}

int		print_segment_64(void *ptr, struct segment_command_64 *seg)
{
	uint32_t			i;
	struct section_64	*sections_arr;
	char				*sectname;

	sections_arr = (struct section_64*)((void*)seg + sizeof(*seg));
	i = 0;
	while (i < seg->nsects)
	{
		sectname = sections_arr[i].sectname;
		if (ft_strcmp(sectname, "__text") == 0)
			print_section_64(ptr, sections_arr + i);
		i++;
	}
	return (0);
}

int		handle_64(void *ptr)
{
	int							cmds_am;
	struct load_command			*lc;

	cmds_am = ((struct mach_header_64*)ptr)->ncmds;
	lc = ptr + sizeof(struct mach_header_64);
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
