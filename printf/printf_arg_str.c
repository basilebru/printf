/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:30:41 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/10 16:25:06 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_prec_str(char **str, int max)
{
	int		i;
	int		j;
	char	*tmp;

	if (max == -1)
		return (0);
	tmp = *str;
	i = 0;
	while (i < max && str[0][i])
		i++;
	if (!(*str = malloc((i + 1) * sizeof(char))))
		return (-1);
	j = 0;
	while (j < i)
	{
		str[0][j] = tmp[j];
		j++;
	}
	str[0][i] = 0;
	free(tmp);
	return (0);
}

int		ft_arg_str(const char *str, q_list p)
{
	int		len;
	int		ret;
	char	*output;

	if (str == NULL)
		output = ft_strdup("(null)");
	else
		output = ft_strdup(str);
	if ((ft_prec_str(&output, p.prec) == -1))
		return (-1);
	len = ft_strlen(output);
	if ((ret = ft_set_field(&output, p.flag, p.width - len, len)) == -1)
		return (-1);
	ft_putstr_fd(output, 1);
	free(output);
	return (ret);
}
