/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 01:56:28 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/08/06 04:27:03 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		count_word(char *str)
{
	int i;
	int l;
	int cn;

	if (str[0] == '\0')
		return (0);
	i = 0;
	l = 0;
	cn = 0;
	while (str[cn])
	{
		if (str[cn] == ' ' || str[cn] == '\n'
			|| str[cn] == '\t' || str[cn] == '\0')
		{
			l = 0;
		}
		else
		{
			if (l == 0)
				i++;
			l = 1;
		}
		cn++;
	}
	return (i);
}

char	*cat_word(char *str, int *n)
{
	char	*word;
	int		i;
	int		start;
	int		end;

	i = *n;
	while (str[i] <= ' ')
		i++;
	start = i;
	while (str[i] > ' ')
		i++;
	end = i;
	*n = i;
	word = (char*)malloc(sizeof(char) * end - start);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	char	**res;
	int		count;
	int		i;

	res = (char**)malloc(sizeof(char*) * count_word(str) + 1);
	count = 0;
	i = 0;
	while (count < count_word(str))
	{
		res[count] = cat_word(str, &i);
		count++;
	}
	res[count] = 0;
	return (res);
}
