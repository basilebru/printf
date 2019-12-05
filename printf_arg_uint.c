/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:15:25 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/05 12:30:21 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	conv_hexa(unsigned int n, char **str, char *base)
{
	int i;
	unsigned int tmp;
	
	tmp = n;
	i = 0;
	while(tmp)
	{
		tmp = tmp / 16;
		i++;
	}
	if (!(*str = malloc((i + 1) * sizeof(**str))))
		return (-1);
	str[0][i] = 0;
	i--;
	while(n)
	{
		str[0][i] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (0);
}

static int	ft_arg_uint_u(unsigned int n, int flag, int width, int prec)
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

static int	ft_arg_uint_x(unsigned int n, int flag, int width, int prec)
{
	char	*nbr;
	int		len;
	int		ret;

	if (n == 0 && prec == 0)
		nbr = ft_strdup("");	
	else if (conv_hexa(n, &nbr, "0123456789abcdef") == -1)
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

static int	ft_arg_uint_X(unsigned int n, int flag, int width, int prec)
{
	char	*nbr;
	int		len;
	int		ret;

	if (n == 0 && prec == 0)
		nbr = ft_strdup("");	
	else if (conv_hexa(n, &nbr, "0123456789ABCDEF") == -1)
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
	
int	ft_arg_uint(unsigned int n, const char id, int flag, int width, int prec)
{	
	int ret;
	
	if (id == 'u')
	{
		if ((ret = ft_arg_uint_u(n, flag, width, prec)) == -1)
			return (-1);
		return (ret);
	}
	if (id == 'x')
	{
		if ((ret = ft_arg_uint_x(n, flag, width, prec)) == -1)
			return (-1);
		return (ret);
	}
	if ((ret = ft_arg_uint_X(n, flag, width, prec)) == -1)
		return (-1);
	return (ret);
}
