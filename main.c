#include "lem_in.h"

int   init_data(t_data *data)
{    
    char	*line;
	int 	ret;

	ret = 1;
     while (get_next_line(0, &line) > 0)
	{
		if ((ret = parse(data, line)) <= 0)
			return (ret);
		free(line);
		if (data->ants)
			printf("value of ants : %d\n", data->ants);
		if (data->vertices)
			print_vertices(data->vertices);
		if (data->edges)
			print_edges(data->edges);
	}
	return (ret);
}

int     main(int ac, char **av)
{
	int		i;
	int		ret;
    t_data data;
	ft_bzero(&data, sizeof(t_data));
	(void)av;
	(void)ac;
	i = 1;
	// if (ac < 2)
	// 	return (0);
    if ((ret = init_data(&data)) <= 0) 
	{
		if (ret == -1)
		{
		write(1, "Error\n", 5);
		return (-1);
		}
		else if (ret == 0)
		{

		}
	}
    return (0);
}
