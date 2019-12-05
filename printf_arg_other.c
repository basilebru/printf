/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:30:41 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/05 13:15:36 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_prec_str(char **str, int max)
{
	// gerer le fait


int		ft_arg_str(char *str, int flag, int width, int prec)
{
	int		len;
	int		ret;

	// ne se termine pas forcement par un null byte
	if (ft_prec_str(&str, prec) == -1) nouvelle fonction a creer pour gerer la prec des str
		return (-1);
	len = ft_strlen(str);
	if ((ret = ft_set_field(&str, flag, width - len, len)) == -1)
		return (-1);
	ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}	
	
