/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:03:57 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/06 16:03:34 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_arg(va_list ap, const char *format, int *i, q_list *p)
{
	int ret;

	ret = 0;
	(*i)++;
	p->flag = 0;
	ft_get_flag(format, i, &(p->flag));
	p->width = 0;
	if (ft_get_width(ap, format, i, &(p->width)) == -1)
		return (-1);
	p->prec = -1;
	if (format[*i] == '.')
	{
	(*i)++;
	if (ft_get_prec(ap, format, i, &(p->prec)) == -1)
		return (-1);
	}
	ft_manage_format(&(p->prec), &(p->flag), &(p->width));
	if ((ret = print_arg(ap, format[*i], *p)) == -1)
		return (-1);
	return (ret);
}

// si plus d'arguments que demande, printf fonctionne et renvoie un warning. -> ft_printf fonctionne (mais pas de warnig). OK ?
// si moins d'arguments que demande, printf emet un warning et son comportement semble undefined. Le retour nest pas -1
// voir dans quels cas printf renvoie "-1", et adapter pour ft_printf (remarque: si on lui donne des flags qui ne correspondent pas a lidentifier (ex: un flag 0 ou une precision avec un 'c'), printf emet un warning pour dire que le comportement est aleatoire --> ne renvoie pas -1. Ces cas de warning ne sont pas a gerer par nous.

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;
	int		count;
	q_list	param;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((ret = ft_arg(ap, format, &i, &param)) == -1)
				return (-1);
			count = count + ret;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
			// si flag = 0 -> pas de flag
			// si width = 0 -> pas de width minimum
			// si prec = -1 -> pas de precision specifiee ou precision negative, ce qui revient au meme

			// verifier que le cas ou on envoie 0 en argument (ou NULL) est bien gere...
			// avec prec, faire attention aux "%.id" (prec = 0), car ils doivent etre geres meme quand l'identifier ne gere pas les prec. Si l'argument est NULL/zero, on affiche rien; sinon pas d'impact
