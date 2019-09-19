/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:14:34 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 21:49:46 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		board_check(t_map *tet_map, t_node *tet_list, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < tet_list->y_max)
	{
		x = 0;
		while (x < tet_list->x_max)
		{
			if (tet_list->unit[y][x] == '#' \
					&& tet_map->board[i + y][j + x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	board_write(tet_map, tet_list, i, j);
	return (1);
}

void	del_write(t_map *tet_map, t_node *tet_list)
{
	int		i;
	int		j;

	i = 0;
	while (i < tet_map->board_size)
	{
		j = 0;
		while (j < tet_map->board_size)
		{
			if (tet_map->board[i][j] == tet_list->sign)
				tet_map->board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		board_solver(t_node *tet_list, t_map *tet_map)
{
	t_node	*temp;
	int		i;
	int		j;

	i = 0;
	temp = tet_list;
	if (!temp)
		return (1);
	while (i < (tet_map->board_size) - (temp->y_max) + 1)
	{
		j = 0;
		while (j < (tet_map->board_size) - (temp->x_max) + 1)
		{
			if (board_check(tet_map, temp, i, j))
			{
				if (board_solver(temp->next, tet_map))
					return (1);
				else
					del_write(tet_map, temp);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	board_write(t_map *tet_map, t_node *tet_list, int i, int j)
{
	int		x;
	int		y;

	y = 0;
	while (y < tet_list->y_max)
	{
		x = 0;
		while (x < tet_list->x_max)
		{
			if (tet_list->unit[y][x] == '#')
				tet_map->board[i + y][j + x] = tet_list->sign;
			x++;
		}
		y++;
	}
}

t_map	*board_main(t_node *tet_list, int size)
{
	t_map	*tet_map;
	int		min_size;

	min_size = size;
	tet_map = create_board(min_size);
	while (!board_solver(tet_list, tet_map))
	{
		min_size++;
		board_free(tet_map);
		tet_map = create_board(min_size);
	}
	return (tet_map);
}
