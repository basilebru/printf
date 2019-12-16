/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wctomb_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:59:58 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 17:44:47 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "libft.h"

static char	*wcto_1b(int n)
{
	char *c;

	if (!(c = malloc(2 * sizeof(*c))))
		return (NULL);
	c[0] = n;
	c[1] = 0;
	return (c);
}

static char	*wcto_2b(int n)
{
	char	*c;
	int		tmp;

	if (!(c = malloc(3 * sizeof(*c))))
		return (NULL);
	tmp = n >> 6;
	tmp = tmp | TWO_BYTES_T;
	c[0] = tmp;
	tmp = n & SIX_UNITS_T;
	tmp = tmp | R_BYTES_T;
	c[1] = tmp;
	c[2] = 0;
	return (c);
}

static char	*wcto_3b(int n)
{
	char	*c;
	int		tmp;
	int		tmp2;

	if (!(c = malloc(4 * sizeof(*c))))
		return (NULL);
	tmp = n >> 12;
	tmp = tmp | THREE_BYTES_T;
	c[0] = tmp;
	tmp = n & TWELVE_UNITS_T;
	tmp2 = tmp >> 6;
	tmp2 = tmp2 | R_BYTES_T;
	c[1] = tmp2;
	tmp = tmp & SIX_UNITS_T;
	tmp = tmp | R_BYTES_T;
	c[2] = tmp;
	c[3] = 0;
	return (c);
}

static char	*wcto_4b(int n)
{
	char	*c;
	int		tmp;
	int		tmp2;

	if (!(c = malloc(5 * sizeof(*c))))
		return (NULL);
	tmp = n >> 18;
	tmp = tmp | FOUR_BYTES_T;
	c[0] = tmp;
	tmp = n & EIGHTEEN_UNITS_T;
	tmp2 = tmp >> 12;
	tmp2 = tmp2 | R_BYTES_T;
	c[1] = tmp2;
	tmp2 = tmp & TWELVE_UNITS_T;
	tmp2 = tmp2 >> 6;
	tmp2 = tmp2 | R_BYTES_T;
	c[2] = tmp2;
	tmp2 = tmp & SIX_UNITS_T;
	tmp2 = tmp2 | R_BYTES_T;
	c[3] = tmp2;
	c[4] = 0;
	return (c);
}

char		*ft_wctomb(int n)
{
	char *output;

	if (byte_num(n) == 1 && (output = wcto_1b(n)))
		return (output);
	if (byte_num(n) == 2 && (output = wcto_2b(n)))
		return (output);
	if (byte_num(n) == 3 && (output = wcto_3b(n)))
		return (output);
	if (byte_num(n) == 4 && (output = wcto_4b(n)))
		return (output);
	return (NULL);
}
