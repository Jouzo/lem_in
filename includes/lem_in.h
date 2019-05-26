#ifndef LEM_IN_H
# define LEM_IN_H
#include "../parsing/includes/parsing.h"
#include "../algo/includes/algo.h"

char	*stringify(t_data *data);
char	**split_vertices(t_vertices *head);
int		output(char *map, t_data *data);
int		ft_printf(const char *format, ...);


#endif
