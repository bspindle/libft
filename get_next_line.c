/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:28:17 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/18 09:56:10 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_file(const int fd, t_file *file, char delim)
{
	int		re;
	char	*buffer;

	if (file->size > 0 && ft_strnchr(file->read_part, delim, file->size))
		return (1);
	buffer = ft_strnew(BUFF_SIZE);
	if (buffer && (re = read(fd, buffer, BUFF_SIZE)) && re != -1)
	{
		if ((file->size && !(file->to_del = ft_strdup(file->read_part)))
					|| (!file->size && !(file->to_del = ft_strnew(1))))
			return (-1);
		if (file->size)
			free(file->read_part);
		file->size += re;
		file->read_part = ft_strnjoin(file->to_del, buffer, file->size);
		if (!file->read_part)
			return (-1);
		free(buffer);
		free(file->to_del);
		return (ft_read_file(fd, file, delim));
	}
	if (!buffer || re == -1)
		return (-1);
	return (0);
}

static int	ft_fill_line(t_file *file, char **line, char delim)
{
	int		i;
	int		len;

	if (file->size <= 0)
		return (0);
	i = 0;
	len = 0;
	while (len < file->size && file->read_part[len] != delim)
		len++;
	(*line) = ft_strdup(file->read_part);
	(*line)[len] = '\0';
	file->size -= (len + 1);
	file->to_del = file->read_part;
	if (file->size > 0)
		file->read_part = ft_strdup(file->to_del + len + 1);
	if (!file->read_part)
		return (-1);
	ft_strdel(&(file->to_del));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	save[OPEN_MAX];
	int				i;

	i = 0;
	if (!line || fd < 0 || fd >= OPEN_MAX)
		return (-1);
	if (!(save[fd].size > 0 &&
				ft_strnchr(save[fd].read_part, '\n', save[fd].size)))
		i = ft_read_file(fd, &save[fd], '\n');
	if (save[fd].size < 0)
		save[fd].size = 0;
	if (i == -1)
		return (-1);
	i = ft_fill_line(&save[fd], line, '\n');
	return (i);
}
