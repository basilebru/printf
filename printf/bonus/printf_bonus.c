/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:03:57 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/11 17:12:00 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "libft.h"

int		ft_arg(va_list ap, const char *format, int *i, q_list *p)
{
	int ret;

	ret = 0;
	(*i)++;
	p->flag = 0;
	ft_get_flag(format, i, &(p->flag));
	p->width = 0;
	if (ft_get_width(ap, format, i, &(p->width)) == -1)
		return (-1);
	p->prec = -1;
	if (format[*i] == '.')
	{
		(*i)++;
		if (ft_get_prec(ap, format, i, &(p->prec)) == -1)
			return (-1);
	}
	ft_get_len(format, i, &(p->len));
	ft_manage_format(&(p->prec), &(p->flag), &(p->width));
	if ((ret = print_arg(ap, format[*i], *p)) == -1)
		return (-1);
	if (p->len)
		free(p->len);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;
	int		count;
	q_list	param;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((ret = ft_arg(ap, format, &i, &param)) == -1)
				return (-1);
			count = count + ret;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
