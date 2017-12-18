/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:47:06 by bspindle          #+#    #+#             */
/*   Updated: 2017/12/18 09:58:51 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50000
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct	s_file
{
	int			size;
	char		*read_part;
	char		*to_del;

}				t_file;

int				get_next_line(const int fd, char **line);
int				get_next_wyw(const int fd, char **line, char c);
char			**get_file(const int fd);

#endif
