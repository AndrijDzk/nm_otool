/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:35:02 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/03 16:30:56 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include "libft.h"

#include "ft_nm.h"

void				*new_empty_symtable(int nsyms)
{
	void		*res;

	if (nsyms <= 0)
		return (NULL);
	res = (struct nlist**)malloc(sizeof(struct nlist*) * nsyms);
	ft_bzero(res, sizeof(struct nlist*) * nsyms);
	return (res);
}

int					remove_duplicate_and_add(struct nlist **symtable,
												int i,
												struct nlist *symbol,
												struct nlist **old)
{
	struct nlist		*new;

	if (symtable == NULL || i < 0 || symbol == NULL || old == NULL)
		return (1);
	new = duplicate_check(symbol + i, *old);
	if (new)
	{
		*old = new;
		symtable[i] = NULL;
	}
	else
		symtable[i] = symbol + i;
	return (0);
}

struct nlist		**get_symtable(char *ptr, int nsyms,
					int symoff, int stof)
{
	int					i;
	struct nlist		*symbol;
	struct nlist		**symtbl;
	struct nlist		**old;

	symtbl = new_empty_symtable(nsyms);
	symbol = (void*)ptr + symoff;
	i = 0;
	while (i < nsyms)
	{
		if (check_symbol_(symbol + i))
		{
			old = find_in_symtable_by_pointer(symtbl, (size_t)nsyms,
			((void*)ptr + stof), (void*)ptr + stof + symbol[i].n_un.n_strx);
			if (old)
				*old = select_better_symbol_for_name(symbol + i, *old);
			else if ((old = find_in_symtable_by_value(symtbl, (size_t)nsyms,
				(void*)ptr + stof, (void*)ptr + stof + symbol[i].n_un.n_strx)))
				remove_duplicate_and_add(symtbl, i, symbol, old);
			else
				symtbl[i] = symbol + i;
		}
		i++;
	}
	return (symtbl);
}
