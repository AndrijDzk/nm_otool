/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_symtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:44:13 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/03 16:27:09 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>

#include "libft.h"

#include "ft_nm.h"

struct nlist	**find_in_symtable_by_pointer(struct nlist **symtable,
					size_t size, char *stringtable, char *name)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (symtable[i] &&
			(stringtable + (symtable[i])->n_un.n_strx == name))
			return (symtable + i);
		i++;
	}
	return (NULL);
}

struct nlist	**find_in_symtable_by_value(struct nlist **symtable,
					size_t size, char *stringtable, char *name)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (symtable[i] &&
			ft_strcmp(stringtable + (symtable[i])->n_un.n_strx, name) == 0)
			return (symtable + i);
		i++;
	}
	return (NULL);
}
