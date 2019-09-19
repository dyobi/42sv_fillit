/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:15:34 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 21:50:48 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		upper_left(char *str)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 4;
	y = 0;
	while (str[i])
	{
		if (str[i] == '#')
			x = ((i % 5) < x) ? (i % 5) : x;
		i++;
	}
	i = 0;
	while (str[i] != '#')
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	return (x + (y * 5));
}

char	*set_str(char *str)
{
	char	*temp;
	int		i;
	int		set;

	i = 0;
	if (!(temp = ft_strnew(16)))
		return (NULL);
	set = upper_left(str);
	while (str[set])
	{
		if (str[set] != '\n')
			temp[i++] = str[set];
		set++;
	}
	while (i < 16)
		temp[i++] = '.';
	return (temp);
}

char	**node_frame(int c)
{
	char	**str;
	int		i;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (c + 1))))
		return (NULL);
	while (i < c)
	{
		if (!(str[i] = ft_strnew(c)))
			return (NULL);
		ft_memset(str[i], '.', c);
		i++;
	}
	str[i] = 0;
	return (str);
}

t_node	*make_node(t_node *tet_list)
{
	t_node	*temp;
	t_node	*curr;

	temp = tet_list;
	if (!tet_list)
	{
		if (!(curr = (t_node*)malloc(sizeof(t_node))))
			return (NULL);
		temp = curr;
	}
	else
	{
		while (tet_list->next)
			tet_list = tet_list->next;
		if (!(curr = (t_node*)malloc(sizeof(t_node))))
			return (NULL);
		tet_list->next = curr;
	}
	if (!(curr->unit = node_frame(4)))
		return (NULL);
	curr->next = NULL;
	return (temp);
}

t_node	*tet_node(t_node *tet_list, char *str)
{
	t_node	*temp;
	char	*tet_str;
	int		i;
	int		j;
	int		k;

	temp = tet_list;
	tet_list = make_node(tet_list);
	if (!temp)
		temp = tet_list;
	while (tet_list->next)
		tet_list = tet_list->next;
	tet_str = set_str(str);
	i = 0;
	k = 0;
	while (tet_str[k])
	{
		j = 0;
		while (j < 4)
			tet_list->unit[i][j++] = tet_str[k++];
		i++;
	}
	ft_strdel(&tet_str);
	return (temp);
}
