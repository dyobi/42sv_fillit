/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_for_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:15:23 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 21:50:40 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	node_rev(t_node *tet_list)
{
	t_node	*temp;

	temp = tet_list;
	temp->pre = NULL;
	while (temp->next)
	{
		temp->next->pre = temp;
		temp = temp->next;
	}
}

void	max_x_y(t_node *tet_list)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	x = 0;
	y = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet_list->unit[i][j] == '#')
			{
				x = (x < j + 1) ? j + 1 : x;
				y = (y < i + 1) ? i + 1 : y;
			}
			j++;
		}
		i++;
	}
	tet_list->x_max = x;
	tet_list->y_max = y;
}

char	**tet_trim_frame(t_node *tet_list)
{
	t_node	*temp;
	char	**trim;
	int		i;
	int		y;

	temp = tet_list;
	if (!(trim = (char**)malloc(sizeof(char*) * (tet_list->y_max + 1))))
		return (NULL);
	i = 0;
	y = tet_list->y_max;
	while (y--)
	{
		if (!(trim[i] = ft_strnew(tet_list->x_max)))
			return (NULL);
		ft_memset(trim[i], '.', tet_list->x_max);
		i++;
	}
	trim[i] = 0;
	return (trim);
}

void	tet_trim(t_node *tet_list)
{
	t_node	*temp;
	char	**trim;
	int		i;
	int		j;

	temp = tet_list;
	trim = tet_trim_frame(temp);
	if (trim)
	{
		i = 0;
		while (i < temp->y_max)
		{
			j = 0;
			while (j < temp->x_max)
			{
				trim[i][j] = temp->unit[i][j];
				j++;
			}
			i++;
		}
		unit_free(tet_list);
		tet_list->unit = trim;
	}
}

void	tet_set_node(t_node *tet_list)
{
	t_node	*temp;
	int		i;

	temp = tet_list;
	i = 0;
	node_rev(tet_list);
	while (temp)
	{
		max_x_y(temp);
		temp->sign = 'A' + i;
		tet_trim(temp);
		temp = temp->next;
		i++;
	}
}
