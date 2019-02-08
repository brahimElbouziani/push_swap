/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:27:44 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/09 17:15:25 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		ft_putstr(char const *s)
{
	while (*s)
		ft_putchar(*s++);
}

size_t		ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] && ++len)
		;
	return (len);
}
