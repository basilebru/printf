/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:07:24 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 17:40:05 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int	ft_arg_int_c(int n, int flag, int width)
{
	char	*c;
	int		ret;

	if (width == 0)
	{
		ft_putchar_fd(n, 1);
		return (1);
	}
	if (!(c = malloc(2 * sizeof(*c))))
		return (-1);
	c[0] = n;
	c[1] = 0;
	if ((ret = ft_set_field(&c, flag, width - 1, 1)) == -1)
		return (-1);
	else
		ft_putstr_fd(c, 1);
	free(c);
	return (ret);
}

static int	ft_arg_int_di(int n, int flag, int width, int prec)
{
	char	*nbr;
	int		len;
	int		ret;

	if (n == 0 && prec == 0)
		nbr = ft_strdup("");
	else if (!(nbr = ft_itoa(n)))
		return (-1);
	len = ft_strlen(nbr);
	if (ft_add_zeros(&nbr, prec - len, len) == -1)
		return (-1);
	len = ft_strlen(nbr);
	if ((ret = ft_set_field(&nbr, flag, width - len, len)) == -1)
		return (-1);
	ft_putstr_fd(nbr, 1);
	free(nbr);
	return (ret);
}

static int	ft_arg_int_di_neg(long int n, int flag, int width, int prec)
{
	char	*tmp;
	char	*nbr;
	int		len;
	int		ret;

	if (!(tmp = ft_itoa(-n)))
		return (-1);
	len = ft_strlen(tmp);
	if (ft_add_zeros(&tmp, prec - len, len) == -1)
		return (-1);
	if (!(nbr = ft_strjoin("-", tmp)))
		return (-1);
	free(tmp);
	len = ft_strlen(nbr);
	if ((ret = ft_set_field(&nbr, flag, width - len, len)) == -1)
		return (-1);
	if (flag == '0' && (width - len) > 0)
	{
		nbr[0] = '-';
		nbr[width - len] = '0';
	}
	ft_putstr_fd(nbr, 1);
	free(nbr);
	return (ret);
}

int			ft_arg_int(int n, const char id, t_flags p)
{
	int ret;

	if (id == 'c')
	{
		if ((ret = ft_arg_int_c(n, p.flag, p.width)) == -1)
			return (-1);
		return (ret);
	}
	else if (n < 0)
	{
		if ((ret = ft_arg_int_di_neg(n, p.flag, p.width, p.prec)) == -1)
			return (-1);
		return (ret);
	}
	if ((ret = ft_arg_int_di(n, p.flag, p.width, p.prec)) == -1)
		return (-1);
	return (ret);
}
