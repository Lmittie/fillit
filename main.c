/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:35:17 by fmallist          #+#    #+#             */
/*   Updated: 2019/10/02 21:33:15 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_read(open(av[1], O_RDONLY));
	else
		ft_putendl("usage: ./fillit [source_file]");
	return (0);
}
