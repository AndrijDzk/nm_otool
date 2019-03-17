/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:15:09 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/21 15:11:09 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <inttypes.h>
# include "libflagfuncs.h"
# include "libconvfuncs.h"
# include "librecall.h"
# include "../libft.h"

int			ft_print_memory(const void *addr, size_t size);

int			ft_count_digits(uintmax_t value, int base);

int			ft_field_width(int digits, int sign, const int *flags, int mode);

int			ft_prefix(int digits, int sign, const int *flags, int mode);

long		ft_power(long value, long power);

uintmax_t	ft_cast(intmax_t value, int *flags);

uintmax_t	ft_initial_check(uintmax_t value, int base);

uintmax_t	ft_min_count(uintmax_t n, int base, const int *flags);

int			ft_max_digits(int *arr, int size);

int			ft_int_arr_prefix(int *info, uintmax_t n2, const int *flags);

void		ft_scan_conv(const char *str, int *flags);

int			ft_scan_prec(const char *str, int j, int *flags);

int			ft_scan_len(const char *str, int j);

int			ft_putchar(char c, const int *flags);

t_fp		*ft_fp_arr_init(void);

int			ft_wstrlen(const wchar_t *str);

int			ft_wcharlen(const wchar_t *c);

char		ft_print_memory_split_condition(size_t const i, const int *flags);

#endif
