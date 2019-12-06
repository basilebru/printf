/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:04:46 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/06 16:13:50 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_add_zeros(char **nbr, int add_num, int len_nbr)
{
	int		i;
	int		j;
	char	*tmp;

	if (add_num <= 0)
		return (0);
	tmp = *nbr;
	if (!(*nbr = malloc((len_nbr + add_num + 1) * sizeof(**nbr))))
		return (-1);
	i = 0;
	while (i < add_num)
	{
		nbr[0][i] = '0';
		i++;
	}
	j = 0;
	while (tmp[j])
	{
		nbr[0][i + j] = tmp[j];
		j++;
	}
	nbr[0][i + j] = 0;
	free(tmp);
	return (0);
}

void	ft_fill_field(char **nbr, const char *tmp, int flag, int add_num)
{
	int i;
	int j;

	i = -1;
	while (flag == 0 && ++i < add_num)
		nbr[0][i] = ' ';
	while (flag == '0' && ++i < add_num)
		nbr[0][i] = '0';
	j = -1;
	while ((flag == 0 || flag == '0') && tmp[++j])
		nbr[0][i + j] = tmp[j];
	while (flag == '-' && tmp[++i])
		nbr[0][i] = tmp[i];
	while (flag == '-' && ++j < add_num)
		nbr[0][i + j] = ' ';
	nbr[0][i + j] = 0;
}

int		ft_set_field(char **nbr, int flag, int add_num, int len_nbr)
{
	char	*tmp;

	if (add_num <= 0)
		return (len_nbr);
	tmp = *nbr;
	if (!(*nbr = malloc((len_nbr + add_num + 1) * sizeof(**nbr))))
		return (-1);
	ft_fill_field(nbr, tmp, flag, add_num);
	free(tmp);
	return (len_nbr + add_num);
}

int		print_other_arg(va_list ap, const char id, q_list params)
{
	const char	*str;
	void		*p;
	int			ret;

	if (id == 's')
	{
		str = va_arg(ap, const char *);
		if ((ret = ft_arg_str(str, params)) == -1)
			return (-1);
		return (ret);
	}
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
	return (0);
}

int		print_arg(va_list ap, const char id, q_list params) // on devrait envoyer un *ap, car ap est modifie a chaque appel de la fonction. Pourtant fonctionne
{
	int				n;
	unsigned int	u;

	printf("|||flag: %d |width: %d |prec: %d |type: %c\n", params.flag, params.width, params.prec, id);
	if (id == 'd' || id == 'i' || id == 'c')
	{
		n = va_arg(ap, int);
		if ((n = ft_arg_int(n, id, params)) == -1)
			return (-1);
		return (n);
	}
	if (id == 'x' || id == 'X' || id == 'u')
	{
		u = va_arg(ap, unsigned int);
		if ((n = ft_arg_uint(u, id, params)) == -1)
			return (-1);
		return (n);
	}
	if ((n = print_other_arg(ap, id, params)) == -1)
		return (-1);
	return (n);
}
