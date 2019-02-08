/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:11:59 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/12 22:24:55 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		retation(t_pile **pile, int len, int bl)
{
	t_pile		*last;
	int			last2;
	int			mark_up;
	int			index;

	if (len < 2)
		return (0);
	last = *pile;
	last2 = (*pile)->value;
	mark_up = (*pile)->mark_up;
	index = (*pile)->index;
	while (len > 1)
	{
		(*pile)->value = ((*pile)->prec)->value;
		(*pile)->mark_up = ((*pile)->prec)->mark_up;
		(*pile)->index = ((*pile)->prec)->index;
		(*pile) = (*pile)->prec;
		len--;
	}
	(*pile)->value = last2;
	(*pile)->mark_up = mark_up;
	(*pile)->index = index;
	(*pile) = last;
	affiche_rota(bl);
	return (1);
}

int		revretation(t_pile **pile, int len, int bl)
{
	int		i;

	i = len;
	while (i > 1)
	{
		retation(pile, len, 0);
		i--;
	}
	if (bl == 1)
		ft_putstr("rra\n");
	else if (bl == 2)
		ft_putstr("rrb\n");
	return (1);
}

void	pile_push(t_pile **pile, int valeur, int *len)
{
	t_pile	*new;

	new = (t_pile*)malloc(sizeof(*new));
	if (!new)
		return ;
	new->value = valeur;
	new->bl = 0;
	new->index = 0;
	new->mark_up = 0;
	new->prec = len == 0 ? NULL : *pile;
	*pile = new;
	*len += 1;
}

int		check_decroissant(t_pile **pile, int lena, int lenb)
{
	int			tmp;
	int			tmp1;
	int			bl;
	t_pile		*last;

	last = *pile;
	bl = 2;
	if (lena < 1 || lenb > 0)
		return (0);
	while (lena > 1)
	{
		tmp = (*pile)->value;
		*pile = (*pile)->prec;
		tmp1 = (*pile)->value;
		if (lena > 0 && tmp >= tmp1)
		{
			*pile = last;
			return (0);
		}
		lena--;
	}
	*pile = last;
	return (1);
}

int		push(t_pile **pile_a, t_pile **pile_b, int *len_a, int *len_b)
{
	t_pile		*last;
	t_pile		*new;

	if (!*pile_a)
		return (0);
	last = (*pile_a)->prec;
	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->value = (*pile_a)->value;
	new->prec = *pile_b;
	(*pile_b) = new;
	(*pile_a) = (last);
	*len_a -= 1;
	*len_b += 1;
	return (1);
}
