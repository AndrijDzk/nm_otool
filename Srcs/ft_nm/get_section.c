/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:37:43 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/03 16:28:26 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stdlib.h>

#include "ft_nm.h"

struct section	*get_section(char *ptr, size_t n)
{
	int							cmds_am;
	struct load_command			*lc;
	struct segment_command		*seg;
	size_t						curr_section;

	cmds_am = ((struct mach_header*)ptr)->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header);
	curr_section = 1;
	while (cmds_am > 0)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			seg = (struct segment_command*)lc;
			if (n >= curr_section && n < (curr_section + seg->nsects))
				return ((void*)seg + sizeof(*seg) +
						sizeof(struct section) * (n - curr_section));
			else
				curr_section += seg->nsects;
		}
		if (lc->cmd == LC_SEGMENT_64)
			return (NULL);
		lc = (void*)lc + lc->cmdsize;
		cmds_am--;
	}
	return (NULL);
}
