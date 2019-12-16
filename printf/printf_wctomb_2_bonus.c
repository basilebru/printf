/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wctomb_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:03:38 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/16 17:44:47 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	bit_num(int a)
{
	int count;

	count = 0;
	while (a)
	{
		a = a >> 1;
		count++;
	}
	return (count);
}

int			byte_num(int count)
{
	count = bit_num(count);
	if (count < 8)
		return (1);
	if (count < 12)
		return (2);
	if (count < 17)
		return (3);
	if (count < 22)
		return (4);
	return (-1);
}
