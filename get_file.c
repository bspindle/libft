/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:59:08 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/14 18:06:23 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**get_file(const int fd)
{
	int		i;
	int		ret;
	char	**line;

	i = 0;
	line = (char **)malloc(sizeof(char*) * 100);
	if (!line)
		return (NULL);
	while ((ret = get_next_line(fd, &line[i])) == 1)
		i++;
	if (ret)
		return (NULL);
	return (line);
}
