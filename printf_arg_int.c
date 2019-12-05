/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:07:24 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/05 20:30:52 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int	ft_arg_int_c(int n, int flag, int width)
{
	char	*c;
	int		ret;

	if (!(c = malloc(2 * sizeof(*c))))
		return (-1);
	c[0] = n;
	c[1] = 0;
	if ((ret = ft_set_field(&c, flag, width - 1, 1)) == -1)
		return (-1);
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

int			ft_arg_int(int n, const char id, int flag, int width, int prec)
{
	int ret;
	
	if (id == 'c')
	{
		if ((ret = ft_arg_int_c(n, flag, width)) == -1)
			return (-1);
		return (ret);
	}
	if ((ret = ft_arg_int_di(n, flag, width, prec)) == -1)
		return (-1);
	return (ret);
}
