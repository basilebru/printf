/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_arg_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:42:05 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 17:43:11 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "libft.h"

static int	ft_get_arg_int_2(long long int *n, va_list ap, char *len)
{
	if (ft_strncmp(len, "l", 2) == 0)
	{
		*n = va_arg(ap, long);
		return (1);
	}
	else if (ft_strncmp(len, "ll", 2) == 0)
	{
		*n = va_arg(ap, long long);
		return (1);
	}
	else if (ft_strncmp(len, "h", 2) == 0)
	{
		*n = (short int)va_arg(ap, int);
		return (1);
	}
	else if (ft_strncmp(len, "hh", 2) == 0)
	{
		*n = (char)va_arg(ap, int);
		return (1);
	}
	else
		return (-1);
}

int			ft_get_arg_int(long long int *n, va_list ap, char *len, int id)
{
	if (!len)
	{
		*n = va_arg(ap, int);
		return (1);
	}
	if (id == 'c')
	{
		if (ft_strncmp(len, "l", 2) == 0)
		{
			*n = va_arg(ap, wint_t);
			return (1);
		}
		return (-1);
	}
	if (ft_get_arg_int_2(n, ap, len) == -1)
		return (-1);
	return (1);
}

static int	ft_get_arg_uint_2(unsigned long long *n, va_list ap, char *len)
{
	if (ft_strncmp(len, "h", 2) == 0)
	{
		*n = (unsigned short int)va_arg(ap, unsigned int);
		return (1);
	}
	else if (ft_strncmp(len, "hh", 2) == 0)
	{
		*n = (unsigned char)va_arg(ap, unsigned int);
		return (1);
	}
	else if (ft_strncmp(len, "l", 2) == 0)
	{
		*n = va_arg(ap, unsigned long);
		return (1);
	}
	else if (ft_strncmp(len, "ll", 2) == 0)
	{
		*n = va_arg(ap, unsigned long long);
		return (1);
	}
	return (-1);
}

int			ft_get_arg_uint(unsigned long long *n, va_list ap, char *len)
{
	if (!len)
	{
		*n = va_arg(ap, unsigned int);
		return (1);
	}
	if (ft_get_arg_uint_2(n, ap, len) == -1)
		return (-1);
	return (1);
}
