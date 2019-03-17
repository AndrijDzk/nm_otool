/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:44:14 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/04 15:55:19 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H
# include <unistd.h>

# define NM_DISP_FUNCS_AM 6

extern int			g_arch;

int					nm(char *ptr, int argc, char **argv, int i);

int					handle_ar(char *ptr, char const *filename);

int					handle_64(void *ptr);

struct nlist_64		**get_symtable_64(char *ptr, int nsm, int smof, int stof);

struct nlist_64		*select_better_symbol_64_for_name(struct nlist_64 *smb1,
						struct nlist_64 *smb2);

struct section_64	*get_section_64(char *ptr, size_t n);

struct nlist_64		**find_in_symtable_64_by_pointer(struct nlist_64 **symtable,
					size_t size, char *stringtable, char *name);

struct nlist_64		**find_in_symtable_64_by_value(struct nlist_64 **symtable,
					size_t size, char *stringtable, char *name);

int					sort_symtable_64(struct nlist_64 **symtable, size_t size,
						char *stringtable);

char				check_symbol_64(struct nlist_64 *smb);

struct nlist_64		*duplicate_check_64(struct nlist_64 *smb1,
										struct nlist_64 *smb2);

int					handle(void *ptr);

struct nlist		**get_symtable(char *ptr, int nsm, int smof, int stof);

struct nlist		*select_better_symbol_for_name(struct nlist *smb1,
						struct nlist *smb2);

struct section		*get_section(char *ptr, size_t n);

struct nlist		**find_in_symtable_by_pointer(struct nlist **symtable,
					size_t size, char *stringtable, char *name);

struct nlist		**find_in_symtable_by_value(struct nlist **symtable,
					size_t size, char *stringtable, char *name);

int					sort_symtable(struct nlist **symtable, size_t size,
						char *stringtable);

char				check_symbol_(struct nlist *smb);

struct nlist		*duplicate_check(struct nlist *smb1,
										struct nlist *smb2);

void				print_filename(char **argv, int i);

int					not_an_object_file(int argc, char **argv, int i);

int					no_such_file_error(int argc, char **argv, int i);

int					handle_fat(void *ptr);

int					handle_fat_64(void *ptr);

void				set_g_arch(void);

void				get_nm_disp_fncs(int (**func_arr)(void*), unsigned int *m);

#endif
