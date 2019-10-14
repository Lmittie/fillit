/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:59:09 by fmallist          #+#    #+#             */
/*   Updated: 2019/10/01 20:59:40 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint64_t		tetramino_mirrorizer(uint64_t tetramino)
{
	uint64_t mirrorized_tetramino;

	mirrorized_tetramino = 0;
	mirrorized_tetramino = ((tetramino << 48) & 0xFFFF000000000000);
	mirrorized_tetramino = ((tetramino << 16) & 0x0000FFFF00000000)
	| mirrorized_tetramino;
	mirrorized_tetramino = ((tetramino >> 16) & 0x00000000FFFF0000)
	| mirrorized_tetramino;
	mirrorized_tetramino = ((tetramino >> 48) & 0x000000000000FFFF)
	| mirrorized_tetramino;
	return (mirrorized_tetramino);
}

int				ft_shift_rows(char const *tmp)
{
	int shift;
	int flag;

	flag = 0;
	shift = 0;
	if (tmp[0] == '.' && tmp[1] == '.' && tmp[2] == '.' && tmp[3] == '.')
		shift += 4;
	else
		flag = 1;
	if ((tmp[5] == '.' && tmp[6] == '.'
		&& tmp[7] == '.' && tmp[8] == '.') && flag != 1)
		shift += 4;
	else
		flag = 1;
	if ((tmp[10] == '.' && tmp[11] == '.'
		&& tmp[12] == '.' && tmp[13] == '.') && flag != 1)
		shift += 4;
	return (shift);
}

int				ft_shift_columns(char const *tmp)
{
	int shift;
	int flag;

	flag = 0;
	shift = 0;
	if (tmp[0] == '.' && tmp[5] == '.'
		&& tmp[10] == '.' && tmp[15] == '.')
		shift += 1;
	else
		flag = 1;
	if ((tmp[1] == '.' && tmp[6] == '.'
		&& tmp[11] == '.' && tmp[16] == '.') && flag != 1)
		shift += 1;
	else
		flag = 1;
	if ((tmp[2] == '.' && tmp[7] == '.'
		&& tmp[12] == '.' && tmp[17] == '.') && flag != 1)
		shift += 1;
	return (shift);
}
