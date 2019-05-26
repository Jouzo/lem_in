#include "includes/lem_in.h"
#include "algo/includes/algo.h"

void	print_data(t_data *data)
{
	printf("current state :\n");
	printf("source : %s\nsink : %s\nants : %d\n", data->source, data->sink, data->ants);
	swap_source(data);
	print_vertices(data->vertices);
	printf("Edges :\n");
	print_edges(data->edges);
}

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
	}
	return (ret);
}

int     main(int ac, char **av)
{
	int		i;
	int		ret;
	t_data data;
	char *map;
	char *graph;
	ft_bzero(&data, sizeof(t_data));
	(void)av;
	(void)ac;
	i = 1;
	if ((ret = init_data(&data)) <= 0) 
	{
		if (ret < 0)
		{	
			if (data.source && data.sink && data.ants && data.edges)
			{

				// DO LEM-IN ALGO
				print_data(&data);
				printf("now calculate ret < 0\n");
				graph = stringify(&data);
				map = algo(&graph, ft_sqrt(ft_strlen(graph)), data.ants);
				output(map, &data);
				free_data(&data);
			}
			else
			{
				print_data(&data);
				free_data(&data);
				write(1, "Error\n", 5);
				return (-1);
			}
		}
		else if (ret == 0)
		{
			free_data(&data);
			write(1, "No ants\n", 8);
		}
	}
	else {
	printf("now calculate ret > 0\n");
	print_data(&data);
	graph = stringify(&data);
	map = algo(&graph, ft_sqrt(ft_strlen(graph)), data.ants);
	// print_flow(flow);
	output(map, &data);
	// free_flow(flow);
	// free_data(&data);
	}
	return (0);
}

// void	reverse_flow(char **map, int vertex)
// {

// }