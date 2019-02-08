/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:33:48 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/12/22 20:21:51 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strnew(0);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (ft_strchr(buff, '\n'))
			break ;
		*line = ft_strjoin(*line, buff);
	}
	if (res == -1)
		return (-1);
	else if (res == 0 || **line == '\0')
		return (0);
	return (1);
}
