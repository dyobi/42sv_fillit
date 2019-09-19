/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:14:20 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/21 20:46:51 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_node
{
	char			**unit;
	char			sign;
	int				x_max;
	int				y_max;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;

typedef struct	s_map
{
	char			**board;
	int				board_size;
}				t_map;


int				valid_check1(char *str);
int				valid_check2(char *str);
t_node			*open_read(char *file);
t_node			*is_valid(int fd);
/*is_valid.c
** valid_check 1 = check the count of the hash and dot.
**                 if it isn't valid, return 0.
** valid_check2 = check the relation of the hashes.
**                if it isn't related well, return 0.
** open_read & is_valid = as getting the file which is arvg, open and read.
**                        if it's wrong file or not valid, return NULL.
**                        if not, return the totally set linked list.
*/

int				upper_left(char *str);
char			*set_str(char *str);
char			**node_frame(int c);
t_node			*make_node(t_node *tet_list);
t_node			*tet_node(t_node *tet_list, char *str);
/*node_link.c
** upper_left = it is for locating up and left.
**              it returns needless index of the string.
** set_str = it returns moved string by upper and left function.
** node_frame = make a pointer to pointer array.
**              it returns **string.
** make_node = it makes a linked list with double array of tetris.
**             it returns the first node of the link.
** tet_node = set the string to list->unit.
**            it returns the first node of the link.
*/

void			node_rev(t_node *tet_list);
void			max_x_y(t_node *tet_list);
void			tet_trim(t_node *tet_list);
void			tet_set_node(t_node *tet_list);
char			**tet_trim_frame(t_node *tet_list);
/*need_for_link.c
** node_rev = set a two-way linked list.
** max_x_y = save the maximum hash's size.
** tet_trim = change the unit array to be trimmed.
** tet_set_node = save whole link of the max size, sign.
**                it takes trimmed array.
** tet_trim_frame = set the array for trim.
**                  it returns double array.
*/

int				map_size_check1(t_node *tet_list);
int				map_size_check2(t_node *tet_list);
int				min_map_size(t_node *tet_list);
t_map			*create_board(int size);
/*get_map_size.c
** map_size_check1 = find the maximum size of the each unit.
**                   if x and y are same, return (size + 1) except only 2 x 2.
**                   if not, bigger size is returned.
** map_size_check2 = find the number of hash of the whole unit.
**                   define the mapsize equal or more than the number of hash.
** min_map_size = compare the minimum size of the map.
**                it returns bigger one.
** create_board = create map struct including min size double array.
*/

t_map			*board_main(t_node *tet_list, int size);
int				board_check(t_map *tet_map, t_node *tet_list, int i, int j);
int				board_solver(t_node *tet_list, t_map *tet_map);
void			board_write(t_map *tet_map, t_node *tet_list, int i, int j);
void			del_write(t_map *tet_map, t_node *tet_list);
/*board.c
** board_check = after giving the index i and j, compare whether OK or NOT.
**               if it is okay, return 1. if not, 0.
** board_solver = solve the board by recursive function.
** board_write = mark from tet_list->sign  to the tet_map->board.
** del_write = delete the sign which point tet_list->sign from board.
*/

void			unit_free(t_node *tet_list);
void			board_free(t_map *tet_map);
void			tetris_free(t_node *tet_list);
void			whole_free(t_map *tet_map, t_node *tet_list);
/*free.c
** unit_free = free the link->unit.
** board_free = free whole t_map struct.
** tetris_free = free whole linked list of tetris.
*/

int				main(int ac, char **av);
/*fillit.c
*/

#endif
