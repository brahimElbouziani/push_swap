/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:04:48 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/16 00:21:34 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			error(void)
{
	ft_putstr("Error\n");
	return (0);
}

void		afficher(t_pile **pile, int len, int bl)
{
	t_pile		*last;
	int			i;

	last = *pile;
	while (len > 0)
	{
		i = -1;
		if (bl == 1)
			ft_putstr(ANSI_COLOR_GREEN);
		else
			(*pile)->value < 0 ? ft_putstr(ANSI_COLOR_ROS)
		: ft_putstr(ANSI_COLOR_BLUE);
		ft_putnbr((*pile)->value);
		while (++i < ABS((*pile)->value))
			ft_putstr(" =");
		ft_putstr("\n");
		*pile = (*pile)->prec;
		ft_putstr(ANSI_COLOR_RESET);
		len--;
	}
	ft_putstr("\n\n");
	*pile = last;
}

void		affichag_2(t_pile **lst_a, t_pile **lst_b, t_var *var)
{
	int bl;

	bl = 0;
	ft_putstr("\e[1;1H\e[2J");
	ft_putstr("\n A \n");
	if (check_decroissant(&*lst_a, var->lena, var->lenb) == 1)
		bl = 1;
	afficher(&*lst_a, var->lena, bl);
	ft_putstr("\n B \n");
	afficher(&*lst_b, var->lenb, 0);
	if (var->lenb + var->lena < 40)
	{
		usleep(800000);
	}
}

void		affiche_rota(int bl)
{
	if (bl == 1)
		ft_putstr("ra\n");
	else if (bl == 2)
		ft_putstr("rb\n");
}
