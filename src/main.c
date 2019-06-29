#include "lem_in.h"

void	print_data(t_data *data)
{
	// // printf("current state :\n");
	// // printf("source : %s\nsink : %s\nants : %d\n", data->source, data->sink, data->ants);
	swap_source(data);
	// if (data->vertices)
		// print_vertices(data->vertices);
	// // printf("Edges :\n");
	// if (data->edges)
		// print_edges(data->edges);
}

int   init_data(t_data *data)
{    
	char	*line;
	int 	ret;

	ret = 1;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		if ((ret = parse(data, line)) <= 0)
		{
			ft_memdel((void**)&line);
			return (ret);
		}
		ft_memdel((void**)&line);
	}
	// // printf("done parsing\n");
	return (ret);
}

int     main(int ac, char **av)
{
	int		i;
	int		ret;
	t_data data;
	char *map;
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
				// // printf("now calculate ret < 0\n");
				map = stringify(&data);
				algo(&map, ft_sqrt(ft_strlen(map)), data.ants);
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
	// // printf("now calculate ret > 0\n");
	print_data(&data);
	map = stringify(&data);
	algo(&map, ft_sqrt(ft_strlen(map)), data.ants);
	// printf("\n");
	// printf("\n");
	// printf("\n");
	// print_flow(flow);
	output(map, &data);
	// free_flow(flow);
	free_data(&data);
	ft_memdel((void**)&map);
	}
	return (0);
}