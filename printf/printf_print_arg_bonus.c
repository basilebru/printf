/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:04:46 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 17:44:49 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "libft.h"

static int		print_other_other_arg(va_list ap, const char id, t_flags params)
{
	void		*p;
	int			ret;

	if (id == 'p')
	{
		p = va_arg(ap, void *);
		if ((ret = ft_arg_uint((unsigned long)p, 'p', params)) == -1)
			return (-1);
		return (ret);
	}
	if (id == '%')
	{
		if ((ret = ft_arg_int(37, 'c', params)) == -1)
			return (-1);
		return (ret);
	}
	return (-1);
}

static int		print_other_arg(va_list ap, const char id, t_flags params)
{
	const char	*str;
	wchar_t		*str_w;
	int			ret;

	if (id == 's' && params.len == NULL)
	{
		str = va_arg(ap, const char *);
		if ((ret = ft_arg_str(str, params)) == -1)
			return (-1);
		return (ret);
	}
	if (id == 's' && params.len)
	{
		str_w = va_arg(ap, wchar_t *);
		if ((ret = ft_arg_wstr(str_w, params)) == -1)
			return (-1);
		return (ret);
	}
	if ((ret = print_other_other_arg(ap, id, params)) == -1)
		return (-1);
	return (ret);
}

int				print_arg(va_list ap, const char id, t_flags params)
{
	long long int			n;
	unsigned long long int	u;

	if (id == 'd' || id == 'i' || id == 'c')
	{
		if (ft_get_arg_int(&n, ap, params.len, id) == -1)
			return (-1);
		if ((n = ft_arg_int(n, id, params)) == -1)
			return (-1);
		return (n);
	}
	if (id == 'x' || id == 'X' || id == 'u')
	{
		if (ft_get_arg_uint(&u, ap, params.len) == -1)
			return (-1);
		if ((n = ft_arg_uint(u, id, params)) == -1)
			return (-1);
		return (n);
	}
	if ((n = print_other_arg(ap, id, params)) == -1)
		return (-1);
	return (n);
}
