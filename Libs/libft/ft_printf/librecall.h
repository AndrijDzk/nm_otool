/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librecall.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:14:47 by adzikovs          #+#    #+#             */
/*   Updated: 2017/01/11 15:23:38 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRECALL_H
# define LIBRECALL_H
# include "libprintf.h"

int		ft_int_recall(va_list par, const int *flags);

int		ft_put_ascii(va_list par, const int *flags);

int		ft_put_short(va_list par, const int *flags);

int		ft_put_long(va_list par, const int *flags);

int		ft_put_long_long(va_list par, const int *flags);

int		ft_put_intmax_t(va_list par, const int *flags);

#endif
