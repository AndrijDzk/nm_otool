/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symtable_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:35:02 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/17 15:16:34 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include "libft.h"

#include "ft_nm.h"

void				*new_empty_symtable_64(int nsyms)
{
	void		*res;

	if (nsyms <= 0)
		return (NULL);
	res = (struct nlist_64**)malloc(sizeof(struct nlist_64*) * nsyms);
	ft_bzero(res, sizeof(struct nlist_64*) * nsyms);
	return (res);
}

int					remove_duplicate_and_add_64(struct nlist_64 **symtable,
												int i,
												struct nlist_64 *symbol,
												struct nlist_64 **old)
{
	struct nlist_64		*new;

	if (symtable == NULL || i < 0 || symbol == NULL || old == NULL)
		return (1);
	new = duplicate_check_64(symbol + i, *old);
	if (new)
	{
		*old = new;
		symtable[i] = NULL;
	}
	else
		symtable[i] = symbol + i;
	return (0);
}

struct nlist_64		**get_symtable_64(char *ptr, int nsyms,
					int symoff, int stof)
{
	int					i;
	struct nlist_64		*symbol;
	struct nlist_64		**symtbl;
	struct nlist_64		**old;

	symtbl = new_empty_symtable_64(nsyms);
	symbol = (void*)ptr + symoff;
	i = 0;
	while (i < nsyms)
	{
		if (check_symbol_64(symbol + i))
		{
			old = find_in_symtable_64_by_pointer(symtbl, (size_t)nsyms,
			((void*)ptr + stof), (void*)ptr + stof + symbol[i].n_un.n_strx);
			if (old)
				*old = select_better_symbol_64_for_name(symbol + i, *old);
			else if ((old = find_in_symtable_64_by_value(symtbl, (size_t)nsyms,
				(void*)ptr + stof, (void*)ptr + stof + symbol[i].n_un.n_strx)))
				remove_duplicate_and_add_64(symtbl, i, symbol, old);
			else
				symtbl[i] = symbol + i;
		}
		i++;
	}
	return (symtbl);
}
