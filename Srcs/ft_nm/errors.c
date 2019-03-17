/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:30:16 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/18 12:30:16 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		no_such_file_error(int argc, char **argv, int i)
{
	if (i >= argc || argv == NULL || argv[0] == NULL || argv[i] == NULL)
		return (-1);
	if (i < 0)
		ft_printf("%$%s: %s: No such file or directory.\n",
					2, argv[0], "./a.out");
	else
		ft_printf("%$%s: %s: No such file or directory.\n\n",
					2, argv[0], argv[i]);
	return (1);
}

int		not_an_object_file(int argc, char **argv, int i)
{
	if (i >= argc || argv == NULL || argv[0] == NULL || argv[i] == NULL)
		return (-1);
	if (i < 0)
		ft_printf("%$%s: %s The file was not "
					"recognized as a valid object file\n",
					2, argv[0], "./a.out");
	else
		ft_printf("%$%s: %s The file was not "
					"recognized as a valid object file\n\n",
					2, argv[0], argv[i]);
	return (1);
}
