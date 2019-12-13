/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_uint2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:01:19 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/11 10:25:13 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "libft.h"

int	ft_arg_uint_p(unsigned long adr, int flag, int width, int prec)
{
	char	*output;
	char	*tmp;
	int		len;
	int		ret;

	if (adr == 0 && prec == 0)
		output = ft_strdup("0x");
	else
	{
		if (conv_hexa(adr, &tmp, "0123456789abcdef") == -1)
			return (-1);
		if (!(output = ft_strjoin("0x", tmp)))
			return (-1);
		free(tmp);
	}
	len = ft_strlen(output);
	if ((ret = ft_set_field(&output, flag, width - len, len)) == -1)
		return (-1);
	ft_putstr_fd(output, 1);
	free(output);
	return (ret);
}
