/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:36:33 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/14 09:36:34 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strnew;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	strnew = ft_strnew(len);
	if (!strnew)
		return (NULL);
	while (i < len)
	{
		strnew[i] = s[start++];
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int			ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, "") == 0 && ft_strcmp(s2, "") == 0)
		return (1);
	if (ft_strcmp(s1, "") == 0 || ft_strcmp(s2, "") == 0)
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}

char		*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*r;
	size_t			len;

	r = (char *)s;
	i = 0;
	len = ft_strlen(r) + 1;
	while (i < len)
	{
		if (r[i] == c)
			return (r + i);
		i++;
	}
	return (0);
}
