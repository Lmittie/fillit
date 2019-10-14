/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetramino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:55:58 by fmallist          #+#    #+#             */
/*   Updated: 2019/10/08 15:55:38 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr			ft_init_tetramino(const char *tmp, int ret)
{
	t_tetr tetramino;

	tetramino.tetramino = ft_create_tetramino(tmp, ret);
	tetramino.x = 0;
	tetramino.y = 0;
	tetramino.height = get_height(tmp);
	tetramino.width = get_width(tmp);
	return (tetramino);
}
