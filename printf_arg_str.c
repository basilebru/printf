/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:30:41 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/06 15:48:45 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_prec_str(const char *str, char **nbr, int max)
{
	int i;
	int j;

	if (max == -1)
		return (0);
	if (max == -2)
		max = 0;
	i = 0;
	while (i < max && str[i])
		i++;
	if (!(*nbr = malloc((i + 1) * sizeof(char))))
		return (-1);
	j = 0;
	while (j < i)
	{
		nbr[0][j] = str[j];
		j++;
	}
	nbr[0][i] = 0;
	return (0);
}

int		ft_arg_str(const char *str, q_list p)
{
	int		len;
	int		ret;
	char	*output;

	if ((ft_prec_str(str, &output, p.prec) == -1))
		return (-1);
	len = ft_strlen(output);
	if ((ret = ft_set_field(&output, p.flag, p.width - len, len)) == -1)
		return (-1);
	ft_putstr_fd(output, 1);
	free(output);
	return (ret);
}
