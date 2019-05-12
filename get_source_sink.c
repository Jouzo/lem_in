#include "lem_in.h"

int get_source_sink(t_data *data, char *s, int st)
{
    printf("inside get_s_t\n");
    char **split;
    int ret;

    ret = 1;
    if (split_arg(data, s, &split) == -1)
        ret = -1;
	if (split_count(split) != 3)
        ret = -1;
	if (!data->vertices)
		if (!(ft_vertice_list(split[0], ft_strlen(split[0]), split[1], split[2])))
            ret = -1;
	else
		if (add_vertices(split[0], ft_strlen(split[0]), split[1], split[2]) == -1)
            ret = -1;
	if (!st)
    	data->source = ft_strdup(s);
	else
  	  data->sink = ft_strdup(s);
    free_split(split);
    return (ret);
}
