#ifndef LEM_IN_H
# define LEM_IN_H
#include "../parsing/includes/parsing.h"
#include "../algo/includes/algo.h"

char	*stringify(t_data *data);
char	**split_vertices(t_vertices *head);
int		output(t_flow *flow, t_data *data);
int		ft_printf(const char *format, ...);
void    print_flow2(t_flow *head, char **vertices);



#endif
