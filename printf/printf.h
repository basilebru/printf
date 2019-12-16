/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:04:15 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 17:39:10 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int	flag;
	int	width;
	int	prec;
}				t_flags;

int				ft_printf(const char *format, ...);
int				print_arg(va_list ap, const char id, t_flags params);
int				ft_arg_int(int n, const char id, t_flags params);
int				ft_add_zeros(char **nbr, int add_num, int len_nbr);
void			ft_fill_field(char **n, const char *t, int f, int add);
int				ft_set_field(char **nbr, int flag, int add_num, int len_nbr);
int				ft_arg_uint(unsigned long n, const char id, t_flags params);
int				ft_arg_str(const char *str, t_flags params);
int				ft_arg_uint_p(unsigned long adr, int flag, int width, int prec);
int				conv_hexa(unsigned long n, char **str, char *base);
int				ft_get_prec(va_list ap, const char *f, int *i, int *prec);
int				ft_get_width(va_list ap, const char *f, int *i, int *width);
void			ft_get_flag(const char *format, int *i, int *flag);
void			ft_manage_format(int *prec, int *flag, int *width);

#endif
