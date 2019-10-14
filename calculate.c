/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:56:14 by fmallist          #+#    #+#             */
/*   Updated: 2019/10/02 21:36:05 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		get_width(char const *tmp)
{
	char width;

	width = 0;
	while (*tmp)
	{
		if (*tmp == '#')
		{
			if (*(tmp - 5) && *(tmp - 5) == '#')
				width--;
			width++;
		}
		tmp++;
	}
	return (width);
}

char		get_height(char const *tmp)
{
	char i;
	char height;

	i = 0;
	height = 0;
	while (*tmp)
	{
		if (*tmp == '#')
		{
			height++;
			tmp = ft_strchr(tmp, '\n') + 1;
		}
		else
			tmp++;
	}
	return (height);
}

int			ft_sqrt(int n)
{
	int		i;

	i = 1;
	while (i < n / 2)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (i);
}
