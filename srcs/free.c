/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:14:58 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 21:50:09 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	unit_free(t_node *tet_list)
{
	int		i;

	i = 0;
	while (tet_list->unit[i])
	{
		free(tet_list->unit[i]);
		i++;
	}
	free(tet_list->unit);
}

void	board_free(t_map *tet_map)
{
	int		i;

	i = 0;
	while (tet_map->board[i])
	{
		free(tet_map->board[i]);
		i++;
	}
	free(tet_map->board);
	free(tet_map);
}

void	tetris_free(t_node *tet_list)
{
	while (tet_list)
	{
		unit_free(tet_list);
		tet_list->pre = NULL;
		free(tet_list);
		tet_list = tet_list->next;
	}
	tet_list = NULL;
}

void	whole_free(t_map *tet_map, t_node *tet_list)
{
	board_free(tet_map);
	tetris_free(tet_list);
}
