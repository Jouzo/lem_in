/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:26:55 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 19:26:56 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "struct_parsing.h"

# define QUIET 1 << 0
# define COLOR 1 << 1
# define MAP 1 << 2
# define LINK 1 << 0

int							parse(t_data *data, char *s);
int							check_hash(t_data *data, char *s);
int							get_source_sink(t_data *data, char *s, int st);
int							split_count(char **split);
int							split_arg(t_data *data, char *s, char ***split);
int							stringify(t_data *data, char **map);
char						**split_vertices(t_vertices *head);
int							get_max_bfs(char *source, char *sink,
									int ants, t_edges *edges);
int							output(char *map, t_data *data);

/*
**  List functions
*/

t_vertices					*new_vertex(char const *name, int x, int y);
int							add_vertex(t_vertices **head,
								char *name, int x, int y);
int							check_vertices_name(t_vertices *head,
								char *name);
size_t						vertices_len(t_vertices *head);
int							check_split(char **split);
t_edges						*new_edge(char const *from, char const *to);
int							add_edge(t_edges **head, char *from, char *to);
int							check_edges_name(t_vertices *head,
								char *from, char *to);
void						swap_source(t_data *data);

/*
**  Free functions
*/

int							free_split(char **split, int ret);
void						free_data(t_data *data);

#endif
