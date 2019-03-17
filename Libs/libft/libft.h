/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:43:50 by adzikovs          #+#    #+#             */
/*   Updated: 2018/07/19 14:12:17 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);

int		ft_atoi(const char *str);

void	ft_bzero(void *addr, size_t size);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strbegins(const char *str, char const *start);

int		ft_strdiff(const char *s1, const char *s2);

int		ft_find_char(char *str, char c);

int		ft_strlen(const char *str);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s1);

char	*ft_strndup(const char *s1, size_t n);

char	*ft_strsub(const char *s, unsigned int start, size_t len);

char	*ft_strjoin(const char *s1, const char *s2);

int		ft_count_digits(uintmax_t value, int base);

#endif
