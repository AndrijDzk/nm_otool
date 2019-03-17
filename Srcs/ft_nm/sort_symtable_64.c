/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symtable_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 11:58:49 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 17:21:27 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include "libft.h"

#include "ft_nm.h"

int					swap_symtable_64(struct nlist_64 **smb1,
										struct nlist_64 **smb2)
{
	struct nlist_64		*tmp;

	if (smb1 == NULL || smb2 == NULL)
		return (1);
	tmp = *smb1;
	*smb1 = *smb2;
	*smb2 = tmp;
	return (0);
}

void				chck_swap_64(char *stringtable,
										struct nlist_64 **smb1,
										struct nlist_64 **smb2)
{
	if (ft_strcmp(stringtable + (*smb1)->n_un.n_strx,
			stringtable + (*smb2)->n_un.n_strx) > 0)
		swap_symtable_64(smb1, smb2);
	else if ((*smb1)->n_value > (*smb2)->n_value)
		swap_symtable_64(smb1, smb2);
}

int					sort_symtable_64(struct nlist_64 **symtable, size_t size,
						char *stringtable)
{
	size_t				i;
	size_t				j;

	if (size == 0)
		return (1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (symtable[j] == NULL || symtable[j + 1] == NULL)
			{
				if (symtable[j] == NULL)
					swap_symtable_64(symtable + j, symtable + j + 1);
			}
			else if (ft_strcmp(stringtable + symtable[j]->n_un.n_strx,
					stringtable + symtable[j + 1]->n_un.n_strx) >= 0)
				chck_swap_64(stringtable, symtable + j, symtable + j + 1);
			j++;
		}
		i++;
	}
	return (0);
}
