#include "lem_in.h"

int   init_data(t_data *data)
{    
    char	*line;
	int 	ret;

	ret = 1;
     while (get_next_line(0, &line) > 0)
	{
		if ((ret = parse(data, line)) <= 0)
		{
			free(line);
			return (ret);
		}
		free(line);
		if (data->ants)
			printf("value of ants : %d\n", data->ants);
		if (data->vertices) {
			print_vertices(data->vertices);
		}
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
    if ((ret = init_data(&data)) <= 0) 
	{
		if (ret == -1)
		{
			if (data.source && data.sink && data.ants)
			{
				// DO LEM-IN ALGO
				printf("current state :\n");
				printf("source : %s\nsink : %s\nants : %s\n : %s\n", data.source, data.sink, data.ants);
				printf("Vertices :\n");
				print_vertices(data.vertices);
				printf("Edges :\n");
				print_edges(data.edges);
				free_data(data);
			}
			else
			{
				free_data(data);
				write(1, "Error\n", 5);
				return (-1);
			}
		}
		else if (ret == 0)
		{
			free_data(data);
			write(1, "No ants\n", 8);
		}
	}
    return (0);
}
