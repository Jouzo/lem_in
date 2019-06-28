#ifndef LEM_IN_H
# define LEM_IN_H
#include "../parsing/includes/parsing.h"
#include "../algo/includes/algo.h"

char	*stringify(t_data *data);
char	**split_vertices(t_vertices *head);
int		output(char *map, t_data *data);
int		ft_printf(const char *format, ...);
void	print_output(char **vertices, t_flow *flow, int ants);

/*
** path functions
*/

int		first_path(char *map, int size);
int		number_of_path(char *map, int size);
int		get_one_path(int start, int size, t_flow **flow, char *map);

/*
** ants functions
*/

int			get_ants_per_path(t_flow *flow, int nb_ants, int nb_path);

#endif
