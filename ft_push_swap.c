/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:06:27 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/22 22:40:38 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		ver_pile_a(t_pile **lst_a, t_pile **lst_b, int *len_a, int *len_b)
{
	int			max_index;
	t_var		var;

	var.min_p = &var.min;
	var.max_p = &var.max;
	var.b = calcu_interva(*len_a);
	while (*len_a > 0)
	{
		if (find_max(lst_a, var.max_p, var.min_p, *len_a) == 0)
			break ;
		var.i = style_ther(*lst_a, var.min, *len_a);
		if ((*lst_a)->mark_up == 0 && ((*lst_a)->value == var.min
			|| (*lst_a)->value < var.min + var.b))
		{
			ft_putstr("pb\n");
			push(&*lst_a, &*lst_b, len_a, len_b);
		}
		else
			excute_rotat_a(lst_a, var.min, len_a, var.i);
		max_index = find_max_index(lst_a, *len_a);
		best_mark_up(&*lst_a, *len_a, max_index);
	}
}

int			ret_pile_b(t_pile **lst_a, t_pile **lst_b, int *len_a, int *len_b)
{
	t_var			var;
	int				a;

	var.min_p = &var.min;
	var.max_p = &var.max;
	var.i = 0;
	while (*len_b > 0)
	{
		find_max(lst_b, var.max_p, var.min_p, *len_b);
		a = style_ther(*lst_b, var.max, *len_b);
		if ((*lst_b)->value == var.max)
		{
			ft_putstr("pa\n");
			push(&*lst_b, &*lst_a, len_b, len_a);
		}
		else
			excute_rotat_b(lst_b, var.max, len_b, a);
	}
	return (var.nb);
}

void		corrige_a(t_pile **lst_a, int *len_a)
{
	while (check_decroissant(&*lst_a, *len_a, 0) == 0)
		revretation(&*lst_a, *len_a, 1);
}

int			main(int argc, char **argv)
{
	t_pile		*lst_a;
	t_pile		*lst_b;
	t_var		var;
	int			max_index;

	inisia_push(&var);
	if (argc < 2 || ajout_lst(argc, argv, &lst_a, &var) == 0 || var.lena == 1)
		return (0);
	max_index = ajouter_index(&lst_a, var.lena);
	best_mark_up(&lst_a, var.lena, max_index);
	if (check_decroissant(&lst_a, var.lena, var.lenb) == 1
		|| test_thre(&lst_a, var.len_a) == 1)
		return (0);
	ver_pile_a(&lst_a, &lst_b, var.len_a, var.len_b);
	corrige_a(&lst_a, var.len_a);
	ret_pile_b(&lst_a, &lst_b, var.len_a, var.len_b);
	free_lst(&lst_a, var.lena);
	free_lst(&lst_b, var.lenb);
	return (0);
}
