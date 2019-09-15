#ifndef OUTPUT_H
# define OUTPUT_H

# include "struct_parsing.h"
# include "struct_lem_in.h"
# include <stdlib.h>

# define LINK 1 << 0
# define TAKEN 1 << 1
# define COLOR 1 << 1

# define RED  "\x1B[31m"
# define RST  "\x1B[0m"

int							output(char *map, t_data *data);
size_t						vertices_len(t_vertices *head);
int							free_split(char **split, int ret);

/*
** path functions
*/

int							number_of_path(char *map, int size);
int							get_one_path(int start,
								t_flow **flow, char *map, int size);

/*
** ants functions
*/

int							get_ants_per_path(t_flow *flow, int nb_ants,
												int nb_path);

/*
** print functions
*/

void						print_output(char **vertices,
										t_flow *flow, int color);
void						print_map(char *s);

/*
** free functions
*/

void						free_flow(t_flow *flow);

#endif
