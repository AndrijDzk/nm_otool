/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 10:42:12 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 16:42:02 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

extern int		g_arch;

void			set_g_arch(void);

int				handle(void *ptr);

int				handle_64(void *ptr);

int				handle_fat(void *ptr);

int				handle_fat_64(void *ptr);

int				handle_ar(char *ptr, char const *filename);

int				print_segment(void *ptr, struct segment_command *seg);

int				print_segment_64(void *ptr, struct segment_command_64 *seg);

int				no_such_file_error(int argc, char **argv, int i);

int				not_an_object_file(int argc, char **argv, int i);

#endif
