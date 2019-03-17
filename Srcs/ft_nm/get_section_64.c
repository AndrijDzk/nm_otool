/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:37:43 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/17 13:37:58 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stdlib.h>

#include "ft_nm.h"

struct section_64	*get_section_64(char *ptr, size_t n)
{
	int							cmds_am;
	struct load_command			*lc;
	struct segment_command_64	*seg;
	size_t						curr_section;

	cmds_am = ((struct mach_header_64*)ptr)->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header_64);
	curr_section = 1;
	while (cmds_am > 0)
	{
		if (lc->cmd == LC_SEGMENT)
			return (NULL);
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64*)lc;
			if (n >= curr_section && n < (curr_section + seg->nsects))
				return ((void*)seg + sizeof(*seg) +
						sizeof(struct section_64) * (n - curr_section));
			else
				curr_section += seg->nsects;
		}
		lc = (void*)lc + lc->cmdsize;
		cmds_am--;
	}
	return (NULL);
}
