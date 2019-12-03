/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:04:46 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/03 17:37:35 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_add_zeros(char **nbr, int add_num, int len_nbr)
{
	int i;
	int j;
	char *tmp;
	
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
	
	//printf("nbr %s, flag %d, add_num %d", tmp, flag, add_num);
	i = 0;
	while(flag == 0 && i < add_num)
	{
		nbr[0][i] = ' ';
		i++;
	}
	while(flag == '0' && i < add_num)
	{
		nbr[0][i] = '0';
		i++;
	}
	j = 0;
	while ((flag == 0 || flag == '0') && tmp[j])
	{
		nbr[0][i + j] = tmp[j];
		j++;
	}
	while (flag == '-' && tmp[i])
	{
		nbr[0][i] = tmp[i];
		i++;
	}
	while (flag == '-' && j < add_num)
	{
		nbr[0][i + j] = ' ';
		j++;
	}
	nbr[0][i + j] = 0;
}

int ft_set_field(char **nbr, int flag, int add_num, int len_nbr)
{
	char	*tmp;

	if (add_num <= 0)
		return (0);
	tmp = *nbr;
	if (!(*nbr = malloc((len_nbr + add_num + 1) * sizeof(**nbr))))
		return (-1);
	ft_fill_field(nbr, tmp, flag, add_num);
	free(tmp);
	return (0);
}


int	ft_arg_int_di(int n, int flag, int width, int prec)
{
	char	*nbr;
	int		len;

	if (n == 0 && prec == 0)
	{
		write(1, "", 0);
		return (0);
	}
	if (!(nbr = ft_itoa(n)))
		return (-1);
	len = ft_strlen(nbr);
	if (ft_add_zeros(&nbr, prec - len, len) == -1)
		return (-1);
	printf("n after zeros: %s\n", nbr);
	len = ft_strlen(nbr);
	if (ft_set_field(&nbr, flag, width - len, len) == -1)
		return (-1);
	ft_putstr_fd(nbr, 1);
	return (0);
}

int	ft_arg_int(int n, const char id, int flag, int width, int prec)
{
	if (id == 'c')
	{
		if (ft_arg_int_c(n, flag, width) == -1)
			return (-1);
		return (0);
	}
	if (ft_arg_int_di(n, flag, width, prec) == -1)
		return (-1);
	return (0);
}


int	print_arg(va_list ap, const char id, int flag, int width, int prec) // on devrait envoyer un *ap, car ap est modifie a chaque appel de la fonction. Pourtant fonctionne
{
	int n;
	unsigned int u;
	const char *str;
	void *p;
	
	printf("|||flag: %d |width: %d |prec: %d |type: %c\n", flag, width, prec, id);
	if (id == 'd' || id == 'i' || id == 'c')
	{
		n = va_arg(ap, int);
		printf("initial n %d\n", n);
		ft_arg_int(n, id, flag, width, prec);
		return (0) ;
	}
	if (id == 'x' || id == 'X' || id == 'u')
	{
		u = va_arg(ap, unsigned int);
		printf("unsigned int %d\n", u);
		return (0) ;
	}
	if (id == 's')
	{
		str = va_arg(ap, const char *);
		printf("const char * %s\n", str);
		return (0) ;
	}
	if (id == 'p')
	{
		p = va_arg(ap, void **);
		printf("void * %p\n", p);
		return (0) ;
	}
	if (id == '%')
	{
		printf("%%\n");
		return (0) ;
	}
	return (0) ;
}
