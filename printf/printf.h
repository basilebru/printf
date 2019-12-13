/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:04:15 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/10 10:48:15 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_H_
# define _PRINTF_H_

#include <stdio.h>
#include <stdarg.h>

typedef struct	p_list
{
	int	flag;
	int	width;
	int	prec;
}				q_list;

int		ft_printf(const char *format, ...);
int		print_arg(va_list ap, const char id, q_list params);
int		ft_arg_int(int n, const char id, q_list params);
int		ft_add_zeros(char **nbr, int add_num, int len_nbr);
void	ft_fill_field(char **nbr, const char *tmp, int flag, int add_num);
int		ft_set_field(char **nbr, int flag, int add_num, int len_nbr);
int		ft_arg_uint(unsigned long n, const char id, q_list params);
int		ft_arg_str(const char *str, q_list params);
int		ft_arg_uint_p(unsigned long adr, int flag, int width, int prec);
int		conv_hexa(unsigned long n, char **str, char *base);
int		ft_get_prec(va_list ap, const char *format, int *i, int *prec);
int		ft_get_width(va_list ap, const char *format, int *i, int *width);
void	ft_get_flag(const char *format, int *i, int *flag);
void	ft_manage_format(int *prec, int *flag, int *width);

	
#endif
