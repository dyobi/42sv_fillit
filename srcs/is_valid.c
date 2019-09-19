/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:15:12 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 21:50:29 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_check1(char *str)
{
	int		i;
	int		count_hash;
	int		count_dot;

	i = 0;
	count_hash = 0;
	count_dot = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count_dot++;
		if (str[i] == '#')
			count_hash++;
		if (i != 0 && ((i + 1) % 5 == 0) && (str[i] != '\n'))
			return (0);
		i++;
	}
	if (str[i] != '\n' && str[i] != '\0')
		return (0);
	return ((count_hash == 4 && count_dot == 12) ? 1 : 0);
}

int		valid_check2(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i <= 13 && str[i + 5] == '#')
				count++;
			if (i >= 5 && str[i - 5] == '#')
				count++;
			if (i >= 1 && str[i - 1] == '#')
				count++;
			if (i <= 17 && str[i + 1] == '#')
				count++;
		}
		i++;
	}
	return ((count >= 6) ? 1 : 0);
}

t_node	*open_read(char *file)
{
	t_node	*tet_list;
	int		fd;
	char	temp[22];

	fd = open(file, O_RDONLY);
	if (read(fd, temp, 0) < 0)
		return (NULL);
	if (!(tet_list = is_valid(fd)))
		return (NULL);
	return (tet_list);
}

t_node	*is_valid(int fd)
{
	t_node	*tet_list;
	int		read_count;
	int		i;
	int		j;
	char	temp[22];

	i = 0;
	j = 0;
	while ((read_count = read(fd, temp, 21)))
	{
		temp[read_count] = '\0';
		if (!valid_check1(temp) || !valid_check2(temp))
			return (NULL);
		if (temp[read_count - 2] == '\n')
			j++;
		tet_list = tet_node(tet_list, temp);
		i++;
	}
	if (j != i - 1 || i > 26)
	{
		tetris_free(tet_list);
		return (NULL);
	}
	tet_set_node(tet_list);
	return (tet_list);
}
