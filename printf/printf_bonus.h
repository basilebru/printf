/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:04:15 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 13:01:38 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_BONUS_H_
# define _PRINTF_BONUS_H_

#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

typedef struct	p_list
{
	int		flag;
	int		width;
	int		prec;
	char	*len;
}				q_list;

int		ft_printf(const char *format, ...);
int		print_arg(va_list ap, const char id, q_list params);
int		ft_arg_int(long long int n, const char id, q_list params);
int		ft_add_zeros(char **nbr, int add_num, int len_nbr);
void	ft_fill_field(char **nbr, const char *tmp, int flag, int add_num);
int		ft_set_field(char **nbr, int flag, int add_num, int len_nbr);
int		ft_arg_uint(unsigned long long n, const char id, q_list params);
int		ft_arg_str(const char *str, q_list params);
int		ft_arg_wstr(int *str, q_list params);
int		ft_arg_uint_p(unsigned long adr, int flag, int width, int prec);
int		conv_hexa(unsigned long long n, char **str, char *base);
int		ft_get_prec(va_list ap, const char *format, int *i, int *prec);
int		ft_get_width(va_list ap, const char *format, int *i, int *width);
void	ft_get_flag(const char *format, int *i, int *flag);
void	ft_manage_format(int *prec, int *flag, int *width);
int		ft_get_len(const char *format, int *i, char **len);
int		ft_get_arg_int(long long int *n, va_list ap, char *len, int id);
int		ft_get_arg_uint(unsigned long long *n, va_list ap, char *len);
char	*ft_wctomb(int n);
int		byte_num(int count);

#define TWO_BYTES_T 192
#define THREE_BYTES_T 224
#define FOUR_BYTES_T 240
#define R_BYTES_T 128
#define SIX_UNITS_T 63
#define TWELVE_UNITS_T 4095
#define EIGHTEEN_UNITS_T 262143
	
#endif
