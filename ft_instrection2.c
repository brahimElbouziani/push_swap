/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instrection2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:38:41 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/15 19:38:44 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		excute_rotat_a(t_pile **lst_a, int min, int *len_a, int i)
{
	if (min == ((*lst_a)->prec)->value)
		swap(&*lst_a, *len_a, 1);
	else if ((*len_a - i) <= i)
		revretation(&*lst_a, *len_a, 1);
	else if (*len_a - i > i)
		retation(&*lst_a, *len_a, 1);
}

void		excute_rotat_b(t_pile **lst_b, int min, int *len_b, int i)
{
	if (min == ((*lst_b)->prec)->value)
		swap(&*lst_b, *len_b, 2);
	else if ((*len_b - i) <= i)
		revretation(&*lst_b, *len_b, 2);
	else if (*len_b - i > i)
		retation(&*lst_b, *len_b, 2);
}

void		swap2(t_pile **lst_a, t_pile **lst_b, t_var *var)
{
	swap(&*lst_a, var->lena, 0);
	swap(&*lst_b, var->lenb, 0);
}

void		rev_retat2(t_pile **lst_a, t_pile **lst_b, t_var *var)
{
	revretation(&*lst_a, var->lena, 0);
	revretation(&*lst_b, var->lenb, 0);
}

int			swap(t_pile **pile, int len, int bl)
{
	int			value;
	t_pile		*last;
	int			index;
	int			mark_up;

	if (len < 2)
		return (-1);
	last = *pile;
	value = (*pile)->value;
	mark_up = (*pile)->mark_up;
	index = (*pile)->index;
	(*pile)->value = ((*pile)->prec)->value;
	(*pile)->mark_up = ((*pile)->prec)->mark_up;
	(*pile)->index = ((*pile)->prec)->index;
	*pile = (*pile)->prec;
	(*pile)->value = value;
	(*pile)->mark_up = mark_up;
	(*pile)->index = index;
	*pile = last;
	if (bl == 1)
		ft_putstr("sa\n");
	else if (bl == 2)
		ft_putstr("sb\n");
	return (1);
}
