/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:45:29 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 15:51:21 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include "libft.h"

#include "ft_nm.h"

char	get_symbol_type_64(char *ptr, uint8_t n_sect, uint8_t n_type)
{
	struct section_64	*sect;

	if ((n_type & N_TYPE) == N_SECT)
	{
		sect = get_section_64(ptr, n_sect);
		if (ft_strcmp(sect->sectname, "__text") == 0)
			return ('T');
		else if (ft_strcmp(sect->sectname, "__data") == 0)
			return ('D');
		else if (ft_strcmp(sect->sectname, "__bss") == 0)
			return ('B');
		else
			return ('S');
	}
	else if ((n_type & N_TYPE) == N_ABS)
		return ('A');
	else if ((n_type & N_TYPE) == N_UNDF)
		return ('U');
	else
		return (0);
}

int		print_symbol_64(uint64_t n_value, char *symbol_type, char *name)
{
	if (symbol_type == NULL || name == NULL)
		return (1);
	if (symbol_type[0] != 'U' && symbol_type[0] != 'u')
		ft_printf("%016llx ", n_value);
	else
		ft_printf("%16.llx ", 0);
	ft_printf(symbol_type);
	ft_printf("%s\n", name);
	return (0);
}

int		print_symtable_64(char *ptr, struct nlist_64 **symtable, size_t size,
			char *stringtable)
{
	size_t		i;
	char		*name;
	char		symbol_type[3];

	symbol_type[1] = ' ';
	symbol_type[2] = 0;
	if (symtable == NULL)
		return (1);
	i = 0;
	while (i < size)
	{
		if (symtable[i])
		{
			symbol_type[0] = get_symbol_type_64(ptr, (symtable[i])->n_sect,
												(symtable[i])->n_type);
			if (symbol_type[0] && (((symtable[i])->n_type) & N_EXT) == 0)
				symbol_type[0] += 32;
			name = stringtable + symtable[i]->n_un.n_strx;
			if (symbol_type[0] && name[0])
				print_symbol_64(symtable[i]->n_value, symbol_type, name);
		}
		i++;
	}
	return (0);
}

int		handle_64(void *ptr)
{
	int							cmds_am;
	struct load_command			*lc;
	struct symtab_command		*sym;
	struct nlist_64				**symtable;
	char						*stringtable;

	cmds_am = ((struct mach_header_64*)ptr)->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header_64);
	while (cmds_am > 0)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			symtable = get_symtable_64(ptr, sym->nsyms, sym->symoff,
										sym->stroff);
			stringtable = (void*)ptr + sym->stroff;
			sort_symtable_64(symtable, (size_t)sym->nsyms, stringtable);
			print_symtable_64(ptr, symtable, (size_t)sym->nsyms, stringtable);
			return (0);
		}
		lc = (void*)lc + lc->cmdsize;
		cmds_am--;
	}
	return (1);
}
