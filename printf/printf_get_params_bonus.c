/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:45:56 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/11 17:11:59 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "libft.h"

int		ft_get_prec(va_list ap, const char *format, int *i, int *prec)
{
	int			p;
	const char	*s;

	if (format[*i] == '*')
	{
		if ((*prec = va_arg(ap, int)) < 0)
			*prec = -1;
		(*i)++;
		return (1);
	}
	p = *i;
	while (ft_isdigit(format[*i]))
		(*i)++;
	if (*i - p)
	{
		if (!(s = ft_substr(format, p, *i - p)))
			return (-1);
		*prec = ft_atoi(s);
		free((char *)s);
	}
	else
		*prec = 0;
	return (1);
}

int		ft_get_width(va_list ap, const char *format, int *i, int *width)
{
	int			p;
	const char	*s;

	if (format[*i] == '*')
	{
		*width = va_arg(ap, int);
		(*i)++;
		return (1);
	}
	p = *i;
	while (format[*i] == '-')
		(*i)++;
	while (ft_isdigit(format[*i]))
		(*i)++;
	if (*i - p)
	{
		if (!(s = ft_substr(format, p, *i - p)))
			return (-1);
		*width = ft_atoi(s);
		free((char *)s);
	}
	return (1);
}

void	ft_get_flag(const char *format, int *i, int *flag)
{
	int zero;
	int minus;

	zero = 0;
	minus = 0;
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0')
			zero = 1;
		else
			minus = 1;
		(*i)++;
	}
	if (minus)
		*flag = '-';
	else if (zero)
		*flag = '0';
}

int		ft_get_len(const char *format, int *i, char **len)
{
	int j;
	
	*len = NULL;
	j = *i;
	while(format[j] == 'l' || format[j] == 'h')
		j++;
	if (j == *i)
		return (1);
	if(!(len[0] = malloc((j + 1) * sizeof(*len))))
		return (-1);
	j = 0;
	while(format[*i] == 'l' || format[*i] == 'h')
	{
		len[0][j] = format[*i];
		(*i)++;
		j++;
	}
	len[0][j] = 0;
	return (1);
}

void	ft_manage_format(int *prec, int *flag, int *width)
{
	if (*prec != -1 && *flag == '0')
		*flag = 0;
	if (*width < 0)
	{
		*width = -(*width);
		*flag = '-';
	}
}
