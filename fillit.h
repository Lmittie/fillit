/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:19:24 by fmallist          #+#    #+#             */
/*   Updated: 2019/10/05 17:17:37 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdint.h>
# include <fcntl.h>

typedef struct	s_tetr
{
	uint64_t	tetramino;
	char		height;
	char		width;
	char		x;
	char		y;
}				t_tetr;

typedef struct	s_map
{
	uint16_t	map[16];
	char		size;
}				t_map;

void			ft_read(const int fd);
void			ft_error(void);
uint64_t		ft_read_tetr(char *tmp);
char			get_width(char const *tmp);
char			get_height(char const *tmp);
int				ft_sqrt(int n);
uint64_t		tetramino_mirrorizer(uint64_t tetramino);
int				ft_shift_rows(char const *tmp);
int				ft_shift_columns(char const *tmp);
void			ft_output(t_map m, t_tetr *t);
t_tetr			ft_init_tetramino(const char *tmp, int ret);
uint64_t		ft_create_tetramino(char const *tmp, int const ret);

#endif
