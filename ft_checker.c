/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:16:18 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/16 11:53:41 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			test_inst(t_pile **lst_a, t_pile **lst_b, t_var *var, char *line)
{
	if (ft_strequ(line, "rra"))
		revretation(&*lst_a, var->lena, 0);
	else if (ft_strequ(line, "rrb"))
		revretation(&*lst_b, var->lenb, 0);
	else if (ft_strequ(line, "ra"))
		retation(&*lst_a, var->lena, 0);
	else if (ft_strequ(line, "rb"))
		retation(&*lst_b, var->lenb, 0);
	else if (ft_strequ(line, "pa"))
		push(&*lst_b, &*lst_a, var->len_b, var->len_a);
	else if (ft_strequ(line, "pb"))
		push(&*lst_a, &*lst_b, var->len_a, var->len_b);
	else if (ft_strequ(line, "sa"))
		swap(&*lst_a, var->lena, 0);
	else if (ft_strequ(line, "ss"))
		swap2(lst_a, lst_b, var);
	else if (ft_strequ(line, "rrr"))
		rev_retat2(lst_a, lst_b, var);
	else if (ft_strequ(line, "sb"))
		swap(&*lst_b, var->lenb, 0);
	else
		return (error());
	return (1);
}

int			traitement(t_pile **lst_a, t_pile **lst_b, t_var *var, char **line)
{
	if (var->lena == 0)
		return (-1);
	while (get_next_line(0, line) != 0)
		if (test_inst(&*lst_a, lst_b, var, *line) == 0)
			return (0);
		else if (var->i == 2)
			affichag_2(&*lst_a, &*lst_b, var);
	if (var->i != 0)
	{
		if (check_decroissant(&*lst_a, var->lena, var->lenb) == 1
			|| (var->lena == 1 && var->lenb == 0))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	free_lst(&*lst_a, var->lena);
	free_lst(&*lst_b, var->lenb);
	return (0);
}

int			main(int argc, char **argv)
{
	t_pile		*lst_a;
	t_pile		*lst_b;
	t_var		var;
	char		*line;

	inisia(&var);
	if (argc < 2)
		return (0);
	if (ft_strequ(argv[1], "-v") == 1)
		var.i = 2;
	if (ajout_lst(argc, argv, &lst_a, &var) == 0)
		return (0);
	if (check(&lst_a, var.lena) == 0)
		return (error());
	traitement(&lst_a, &lst_b, &var, &line);
	free(line);
	return (0);
}
