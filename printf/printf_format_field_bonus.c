/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_field_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:39:43 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 12:40:55 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
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
