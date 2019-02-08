/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:41:50 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/14 16:41:52 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		inisia(t_var *var)
{
	var->lena = 0;
	var->lenb = 0;
	var->len_a = &var->lena;
	var->len_b = &var->lenb;
	var->i = 1;
}

void		inisia_push(t_var *var)
{
	var->lena = 0;
	var->lenb = 0;
	var->len_a = &var->lena;
	var->len_b = &var->lenb;
	var->i = 1;
	var->nb = 0;
}

void		free_lst(t_pile **pile, int len)
{
	t_pile	*last;

	last = *pile;
	while (len > 0)
	{
		free(*pile);
		*pile = (*pile)->prec;
		len--;
	}
}

int			calcu_interva(int lena)
{
	if (lena < 30)
		return (0);
	else if (lena > 90 && lena < 120)
		return (15);
	else if (lena < 90 && lena > 15)
		return (20);
	else if (lena > 90)
		return (50);
	return (0);
}
