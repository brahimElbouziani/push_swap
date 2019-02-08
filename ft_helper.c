/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:12:27 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/22 23:43:26 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			ajouter_index(t_pile **pile, int len_a)
{
	t_pile			*last;
	t_pile			*min;
	t_var			var;

	var.i = 0;
	last = *pile;
	var.lena = len_a;
	while (++var.i <= len_a)
	{
		var.lena = len_a + 1;
		while (--var.lena && (*pile)->bl == 1)
			*pile = (*pile)->prec;
		min = (*pile);
		while (var.lena-- > 0)
		{
			if (min->value > (*pile)->value && (*pile)->bl == 0)
				min = (*pile);
			*pile = (*pile)->prec;
		}
		*pile = min;
		(*pile)->index = var.i;
		(*pile)->bl = 1;
		*pile = last;
	}
	return (var.i - 1);
}

void		mark_up2(t_pile **pile, int len_a, int max_index, int i_max)
{
	t_pile		*last;
	int			i;

	i = 0;
	last = *pile;
	while (i < len_a)
	{
		if (i > i_max && (*pile)->index == max_index)
		{
			len_a = i;
			i = 0;
			max_index--;
			(*pile)->mark_up = 1;
			*pile = last;
		}
		else
		{
			i++;
			*(pile) = (*pile)->prec;
		}
	}
	*pile = last;
}

void		best_mark_up(t_pile **pile, int len_a, int max_index)
{
	t_pile		*last;
	t_var		var;

	var.i = 0;
	last = *pile;
	var.nb = len_a;
	var.max = len_a + 1;
	while (var.i < len_a)
		if ((*pile)->index == max_index)
		{
			len_a = var.i;
			if (var.max == var.nb + 1)
				var.max = var.i;
			var.i = 0;
			max_index--;
			(*pile)->mark_up = 1;
			*pile = last;
		}
		else
		{
			var.i++;
			*(pile) = (*pile)->prec;
		}
	*pile = last;
	mark_up2(&*pile, var.nb, max_index, var.max);
}

int			ajout_lst(int argc, char **argv, t_pile **lst_a, t_var *var)
{
	int			tmp;
	char		**tab;
	int			a;

	a = 0;
	tmp = argc;
	while (--argc >= var->i)
	{
		tab = ft_split_whitespaces(argv[argc]);
		a = calcul_len(tab) - 1;
		while (a >= 0)
		{
			if (ft_atoi_check(tab[a]) == 0)
				return (error());
			pile_push(lst_a, ft_atoi(tab[a]), var->len_a);
			a--;
		}
	}
	free(tab);
	argc = tmp;
	if (check(lst_a, var->lena) == 0)
		return (error());
	return (1);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' ||
			*(str + i) == '\t' ||
			*(str + i) == '\r' ||
			*(str + i) == '\v' ||
			*(str + i) == '\f' ||
			*(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
	}
	return (num * sign);
}
