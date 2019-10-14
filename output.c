/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:31:50 by fmallist          #+#    #+#             */
/*   Updated: 2019/10/05 18:05:22 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char		*init_map(t_map m)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = ft_strnew(m.size * m.size + m.size)))
		ft_error();
	ft_memset(out, '.', m.size * m.size + m.size);
	while (out[i])
	{
		if (!((i + 1) % (m.size + 1)))
			out[i] = '\n';
		i++;
	}
	return (out);
}

void			ft_output(t_map m, t_tetr *t)
{
	char		*out;
	int			i;
	int			x;
	int			y;

	i = -1;
	out = init_map(m);
	while (t[++i].tetramino != 0)
	{
		y = -1;
		while (++y < t[i].height)
		{
			x = -1;
			while (++x < t[i].width)
				if ((t[i].tetramino >> (16 * (y + 1) - x - 1)) & 1)
					out[(t[i].y + y) * (m.size + 1) + x + t[i].x] = 'A' + i;
		}
	}
	ft_putstr(out);
	ft_strdel(&out);
}
