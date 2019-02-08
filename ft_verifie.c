/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:22:36 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/14 21:22:39 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			check_double(t_pile **pile, int double_, int len)
{
	t_pile		*last;
	int			i;
	int			j;

	last = *pile;
	i = 0;
	j = 0;
	while (len > 0)
	{
		if (double_ == (*pile)->value)
		{
			if (j == 1)
				return (0);
			j = 1;
		}
		*pile = (*pile)->prec;
		len--;
	}
	*pile = last;
	return (1);
}

int			check(t_pile **pile, int len)
{
	t_pile		*last;
	t_pile		**tmp;
	int			i;

	tmp = pile;
	last = *pile;
	i = 0;
	while (len > 1)
	{
		if (check_double(tmp, (*pile)->value, len) == 0)
			return (0);
		*pile = (*pile)->prec;
		len--;
	}
	*pile = last;
	return (1);
}

int			ft_atoi_check(const char *str)
{
	int				i;
	long long int	num;
	int				bl;

	i = 0;
	num = 0;
	bl = 0;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		bl = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > 2147483647)
			return (0);
		i++;
	}
	if (i != (int)ft_strlen(str) || (i == 1 && bl == 1))
		return (0);
	return (1);
}

void		ft_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
