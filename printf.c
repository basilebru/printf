/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:03:57 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/03 19:08:50 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_get_prec(va_list ap, const char *format, int *i, int *prec)
{
	int p;
	const char *s;

	*prec = -1;
	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			if ((*prec = va_arg(ap, int)) < 0)
				*prec = -2;
			(*i)++;
			return (1);
		}
		p = *i;
		while(ft_isdigit(format[*i]))
			(*i)++;
		if (*i - p)
		{
			if (!(s = ft_substr(format, p, *i - p)))
				return (-1);
			*prec = ft_atoi(s);
			free ((char *)s);
		}
		else
			*prec = 0;
	}
	return (1);
}	

int	ft_get_width(va_list ap, const char *format, int *i, int *width)
{
	int p;
	const char *s;

	*width = 0;
	if (format[*i] == '*')
	{
		*width = va_arg(ap, int);
		(*i)++;
		return (1);
	}	
	p = *i;
	while (format[*i] == '-')
		(*i)++;
	while(ft_isdigit(format[*i]))
		(*i)++;
	if (*i - p)
	{
		if (!(s = ft_substr(format, p, *i - p)))
			return (-1);
		*width = ft_atoi(s);
		free ((char *)s);
	}
	return (1);
}

void ft_get_flag(const char *format, int *i, int *flag)
{
	int zero;
	int minus;

	*flag = 0;
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

int		ft_arg(va_list ap, const char *format, int *i, int *flag, int *width, int *prec)
{
	int ret;

	ret = 0;
	(*i)++;
	ft_get_flag(format, i, flag);
	if (ft_get_width(ap, format, i, width) == -1)
		return (-1);
	if (ft_get_prec(ap, format, i, prec) == -1)
		return (-1);
	ft_manage_format(prec, flag, width);
	if ((ret = print_arg(ap, format[*i], *flag, *width, *prec)) == -1)
		return (-1);
	return (ret);
}

// si plus d'arguments que demande, printf fonctionne et renvoie un warning. -> ft_printf fonctionne (mais pas de warnig). OK ?
// si moins d'arguments que demande, printf emet un warning et son comportement semble undefined. Le retour nest pas -1
// voir dans quels cas printf renvoie "-1", et adapter pour ft_printf
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int i;
	int flag;
	int width;
	int	prec;
	int count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((flag = ft_arg(ap, format, &i, &flag, &width, &prec)) == -1)
				return (-1);
			count = count + flag;
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
			// si flag = 0 -> pas de flag
			// si width = 0 -> pas de width minimum
			// si prec = -1 -> pas de precision specifiee
			// si prec = -2 -> precision implicite a zero au sens du man pour les conversions d, i, x, X, u: printf renvoie empty si on lui envoie zero avec une precision explicite a zero ("%.0d": explicite "%.d": explicite <> "%.*d" avec *renvoyant a un int negatif: implicite. 

int	main()
{
		int a;
		int ret;
		
		a = 2222;
		
		ret = 0;
		ret = ft_printf("%-10.5d", a);
		printf("end\n");
		printf("ret: %d\n", ret);
		
		ret = 0;
		ret = printf("%-10.5d", a);
		printf("end\n");
		printf("ret: %d\n", ret);
}

