/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:15:05 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 21:50:17 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_size_check1(t_node *tet_list)
{
	t_node	*temp;
	int		x;
	int		y;

	temp = tet_list;
	x = 0;
	y = 0;
	while (temp)
	{
		x = (temp->x_max > x) ? temp->x_max : x;
		y = (temp->y_max > y) ? temp->y_max : y;
		temp = temp->next;
	}
	if (x == y && x != 2)
		return (x + 1);
	return ((x >= y) ? x : y);
}

int		map_size_check2(t_node *tet_list)
{
	t_node	*temp;
	int		i;
	int		n;

	temp = tet_list;
	i = 1;
	n = 2;
	while (temp)
	{
		if (!temp->next)
			break ;
		temp = temp->next;
		i++;
	}
	i *= 4;
	while (i > (n * n))
		n++;
	return (n);
}

int		min_map_size(t_node *tet_list)
{
	int		check1;
	int		check2;

	check1 = map_size_check1(tet_list);
	check2 = map_size_check2(tet_list);
	return (check1 >= check2 ? check1 : check2);
}

t_map	*create_board(int size)
{
	t_map	*tet_map;
	char	**map;

	if (!(tet_map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map = node_frame(size)))
		return (NULL);
	tet_map->board = map;
	tet_map->board_size = size;
	return (tet_map);
}
