/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_better_symbol_64.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:00:01 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/17 15:33:01 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mach-o/nlist.h>

#include "libft.h"

#include "ft_nm.h"

char				compare_nlist_64(struct nlist_64 *smb1,
									struct nlist_64 *smb2)
{
	if (smb1->n_un.n_strx == smb2->n_un.n_strx &&
		smb1->n_type == smb2->n_type &&
		smb1->n_sect == smb2->n_sect &&
		smb1->n_desc == smb2->n_desc)
		return (1);
	else
		return (0);
}

char				check_symbol_64(struct nlist_64 *smb)
{
	uint16_t	n_desc_without_type;
	uint16_t	n_desc_type;

	n_desc_without_type = (smb->n_desc) & (~REFERENCE_TYPE);
	n_desc_type = (smb->n_desc) & REFERENCE_TYPE;
	if (n_desc_type == REFERENCE_FLAG_UNDEFINED_LAZY)
		return (0);
	return (1);
}

struct nlist_64		*duplicate_check_64(struct nlist_64 *smb1,
										struct nlist_64 *smb2)
{
	if (smb1->n_type != smb2->n_type)
	{
		if (((smb1->n_type) & N_TYPE) == N_UNDF)
			return (smb2);
		else if (((smb2->n_type) & N_TYPE) == N_UNDF)
			return (smb1);
		else
			return (NULL);
	}
	else
		return (NULL);
}

struct nlist_64		*select_better_symbol_64_for_name(struct nlist_64 *smb1,
						struct nlist_64 *smb2)
{
	uint16_t	n_desc1;
	uint16_t	n_desc_type1;
	uint16_t	n_desc_type2;

	if (smb1 == NULL)
		return (smb2);
	else if (smb2 == NULL)
		return (smb1);
	n_desc1 = (smb1->n_desc) & (~REFERENCE_TYPE);
	n_desc_type1 = (smb1->n_desc) & REFERENCE_TYPE;
	n_desc_type2 = (smb2->n_desc) & REFERENCE_TYPE;
	if (n_desc_type1 != n_desc_type2 &&
			n_desc_type1 == REFERENCE_FLAG_UNDEFINED_LAZY)
		return (smb2);
	else if (n_desc_type1 != n_desc_type2 &&
			n_desc_type2 == REFERENCE_FLAG_UNDEFINED_LAZY)
		return (smb1);
	else if ((smb1->n_type & N_STAB) == 0 && (smb2->n_type & N_STAB) != 0)
		return (smb1);
	else if ((smb1->n_type & N_STAB) != 0 && (smb2->n_type & N_STAB) == 0)
		return (smb2);
	else if (((smb1->n_type) & N_EXT) && n_desc1 != REFERENCED_DYNAMICALLY)
		return (smb1);
	else
		return (smb2);
}
