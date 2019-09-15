/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:26:48 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 22:38:18 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdbool.h>
# include <stdlib.h>
# include "struct_lem_in.h"

# define INITIAL 1
# define WAITING 2
# define VISITED 3
# define LINK 1 << 0
# define TAKEN 1 << 1
# define QUIET 1 << 0
# define COLOR 1 << 1
# define MAP 1 << 2

/*
****************************************
***********     FUNCTIONS     **********
****************************************
*/

/*
**  algo functions
*/

void						algo(char **edges, int nb_vertices,
								int max_bfs, int nb_ant);
void						reinit_args(t_args *args);

/*
**  bfs functions
*/

t_path						*bfs(t_args *args);
int							check_available(char *state, int vertex);
void						change_state(char **state, int vertex,
											int new_state);
/*
** queue functions
*/

bool						is_empty(t_queue *queue);
int							dequeue(t_queue *queue);
void						enqueue(t_queue *queue, int vertex);
void						free_queue_vertex(t_queue *queue);

/*
** linked list functions for t_path
*/

int							push_vertex(t_path **head, int vertex);
t_path						*init_path(int vertex);

/*
** linked list functions for t_flow
*/

t_flow						*new_flow(t_path *head, int size);
int							add_flow(t_flow **head, t_flow *new);

/*
**  free functions
*/

void						free_queue(t_queue *queue);
void						free_path(t_path *head);
void						free_flow(t_flow *flow);
void						free_args(t_args *args);

/*
**	path functions
*/

bool						find_path(t_args *args);
bool						get_path(t_args *args);

/*
**	update functions
*/

void						update_from_path(t_args *args, char *map, int u);

/*
**	yield functions
*/

bool						check_path_yield(t_args *args, int size);

/*
** check path functions
*/

bool						check_used_link(t_args *args, int vertex, int i);
bool						check_link(t_args *args, int vertex, int i);
bool						check_end(t_args *args, int vertex, int i);
bool						check_taken(t_args *args, int vertex);
bool						check_connection(t_args *args, int vertex, int to);
int							get_previous(int vertex, t_args *args);

#endif
