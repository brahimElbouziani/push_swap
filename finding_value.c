/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:34:40 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/23 23:34:42 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <swap.h>

int			calcul_len(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

int			find_max_index(t_pile **pile, int len)
{
	t_pile			*last;
	int				max;

	last = *pile;
	max = 0;
	if (len == 0)
	{
		*pile = last;
		return (0);
	}
	max = (*pile)->index;
	while (len > 0)
	{
		max = (max < (*pile)->index) ? (*pile)->index : max;
		*pile = (*pile)->prec;
		len--;
	}
	*pile = last;
	return (max);
}

int			test_thre(t_pile **lst_a, int *len_a)
{
	swap(&*lst_a, *len_a, 0);
	retation(&*lst_a, *len_a, 0);
	retation(&*lst_a, *len_a, 0);
	if (check_decroissant(&*lst_a, *len_a, 0) == 1)
	{
		ft_putstr("sa\nra\nra\n");
		return (1);
	}
	else
	{
		revretation(&*lst_a, *len_a, 0);
		revretation(&*lst_a, *len_a, 0);
		swap(&*lst_a, *len_a, 0);
		return (0);
	}
	return (0);
}

int			find_max(t_pile **pile, int *max, int *min, int len)
{
	t_pile			*last;

	last = *pile;
	len++;
	while (--len > 0 && (*pile)->mark_up == 1)
		*pile = (*pile)->prec;
	if (len == 0)
	{
		*pile = last;
		return (0);
	}
	*min = (*pile)->value;
	*max = (*pile)->value;
	while (len > 0)
	{
		if ((*pile)->mark_up == 0)
		{
			*max = (*max < (*pile)->value) ? (*pile)->value : *max;
			*min = (*min > (*pile)->value) ? (*pile)->value : *min;
		}
		*pile = (*pile)->prec;
		len--;
	}
	*pile = last;
	return (1);
}

int			style_ther(t_pile *pile, int temp, int len)
{
	int			i;
	t_pile		*last;

	i = 0;
	last = pile;
	while (len > 0)
	{
		if ((*pile).value == temp)
			return (i);
		pile = pile->prec;
		len--;
		i++;
	}
	pile = last;
	return (0);
}
