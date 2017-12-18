/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:24:20 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/20 09:45:58 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	if (!(newstr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		newstr[i] = '\0';
		i++;
	}
	return (newstr);
}
