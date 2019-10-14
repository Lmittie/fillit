/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:24:27 by fmallist          #+#    #+#             */
/*   Updated: 2019/10/05 18:10:46 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_check_place(t_tetr *t, t_map *m)
{
	t->y = 0;
	if (t->tetramino == 0)
		return (1);
	while (t->y <= m->size - t->height)
	{
		t->x = 0;
		while (t->x <= m->size - t->width)
		{
			if (!((t->tetramino >> t->x) & (*(uint64_t *)(m->map + t->y))))
			{
				*((uint64_t *)(m->map + t->y)) ^= (t->tetramino >> t->x);
				if (ft_check_place(t + 1, m))
					return (1);
				*((uint64_t *)(m->map + t->y)) ^= (t->tetramino >> t->x);
			}
			t->x++;
		}
		t->y++;
	}
	return (0);
}

void			ft_solve(t_tetr tetra_array[27], int map_size)
{
	t_map map;

	map.size = map_size;
	while (map.size < 16)
	{
		ft_bzero(map.map, sizeof(uint16_t) * 16);
		if (ft_check_place(tetra_array, &map))
		{
			ft_output(map, tetra_array);
			return ;
		}
		map.size++;
	}
}

void			ft_check_tetramino(uint64_t t, uint8_t ret, uint8_t linebreaks)
{
	if ((t ^ 3221274624
		&& t ^ 61440
		&& t ^ 9223512776490647552ULL
		&& t ^ 140739635888128
		&& t ^ 1610661888
		&& t ^ 3758129152
		&& t ^ 211108380049408
		&& t ^ 3221250048
		&& t ^ 140740709613568
		&& t ^ 70369817968640
		&& t ^ 536928256
		&& t ^ 3758104576
		&& t ^ 1073799168
		&& t ^ 3758112768
		&& t ^ 2147540992
		&& t ^ 70371965419520
		&& t ^ 211107306291200
		&& t ^ 140740709597184
		&& t ^ 70371965435904))
		ft_error();
	if ((ret == 20 && linebreaks != 4) || (ret == 21 && linebreaks != 5))
		ft_error();
}

uint64_t		ft_create_tetramino(char const *tmp, int const ret)
{
	uint64_t	tetraminka;
	int			i;
	int			pos;
	int			lb;

	tetraminka = 0;
	i = -1;
	pos = 0;
	lb = 0;
	while (tmp[++i])
	{
		if (tmp[i] == '#')
		{
			tetraminka = tetraminka | ((uint64_t)1 << (63 - i - pos + lb));
			if (tmp[i + 1] == '.' || tmp[i + 1] == '\n')
				pos += 12;
		}
		else if (tmp[i] == '\n')
			lb++;
		else if (tmp[i] != '\n' && tmp[i] != '.' && tmp[i] != '#')
			ft_error();
	}
	tetraminka <<= (ft_shift_rows(tmp) + ft_shift_columns(tmp));
	ft_check_tetramino(tetramino_mirrorizer(tetraminka), ret, lb);
	return (tetramino_mirrorizer(tetraminka));
}

void			ft_read(const int fd)
{
	int				ret;
	char			tmp[22];
	uint8_t			i;
	t_tetr			tetra_array[27];
	uint8_t			map_size;

	i = 0;
	if (fd < 0)
		ft_error();
	while ((ret = read(fd, tmp, 21)) >= 20)
	{
		if (i >= 26)
			ft_error();
		tmp[ret] = '\0';
		tetra_array[i] = ft_init_tetramino(tmp, ret);
		i++;
		map_size = ret;
	}
	if (ret != 0 || (ret == 0 && i == 0) || (ret == 0 && map_size == 21))
		ft_error();
	tetra_array[i].tetramino = 0;
	map_size = ft_sqrt(i * 4);
	ft_solve(tetra_array, map_size);
}
