#ifndef LEM_IN_H
# define LEM_IN_H
#include "../parsing/includes/parsing.h"
#include "../algo/includes/algo.h"

char	*stringify(t_data *data);
char	**split_vertices(t_vertices *head);
int		output(char *map, t_data *data);
int		ft_printf(const char *format, ...);
int		get_one_path(int start, int size, t_flow **flow, char *map);
int		first_path(char *map, int size);
void	print_output(char *s, char **vertices, t_flow *flow, int ants);

#endif
