/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:14:41 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 21:49:56 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_node	*tet_list;
	t_map	*tet_map;
	int		i;
	int		j;

	if (ac != 2)
		ft_putstr("USG : ./fillit target_file\n");
	else if (!(tet_list = open_read(av[1])))
		ft_putstr("error\n");
	else
	{
		i = min_map_size(tet_list);
		j = 0;
		tet_map = board_main(tet_list, i);
		while (tet_map->board[j])
		{
			ft_putstr(tet_map->board[j]);
			ft_putchar('\n');
			j++;
		}
		whole_free(tet_map, tet_list);
	}
	return (0);
}
