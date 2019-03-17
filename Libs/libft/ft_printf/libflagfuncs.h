/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflagfuncs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:27:37 by adzikovs          #+#    #+#             */
/*   Updated: 2017/04/04 10:58:23 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFLAGFUNCS_H
# define LIBFLAGFUNCS_H

typedef	void	(*t_fl_fp)(int *);

void		ft_flag_hash(int *flags);

void		ft_flag_zero(int *flags);

void		ft_flag_minus(int *flags);

void		ft_flag_plus(int *flags);

void		ft_flag_space(int *flags);

#endif
