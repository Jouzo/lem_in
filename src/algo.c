#include "lem_in.h"

static t_args	*init_args(int nb_vertices, char **edges, int max_bfs, int nb_ant)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = ft_strnew(nb_vertices)))
		return (NULL);
	if (!(args->taken = ft_memalloc((nb_vertices + 1) * sizeof(int))))
		return (NULL);
	if (!(args->update = ft_memalloc(sizeof(t_update))))
		return (NULL);
	ft_memset(args->state, INITIAL, nb_vertices);
	args->max_bfs = max_bfs;
	args->nb_ant = nb_ant;
	args->step_number = 0;
	args->edges = *edges;
	args->nb_vertice = nb_vertices;
	args->queue = create_queue();
	return (args);
}

void	reinit_args(t_args *args)
{
	ft_memset(args->state, INITIAL, strlen(args->state));
	if (!(args->update = ft_memalloc(sizeof(t_update))))
		exit(1);
	initialize(args->queue);
}

/*
in the matrix, check if there is more than two '2 in the line
which means the paths found are invlalid
*/

void	check_line(char *map)
{
	int size;
	int i;
	int j;
	int count;

	i = 0;
	size = ft_sqrt(ft_strlen(map));
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (map[i * size + j] == TAKEN)
				count++;
			j++;
		}
		i++;
	}
}

void	set_taken(t_args *args, t_path *path)
{
	t_path *tmp;

	tmp = path;
	while (tmp)
	{
		if (tmp->vertex && tmp->vertex != args->nb_vertice - 1) {
			args->taken[tmp->vertex] = 1;
		}
		tmp = tmp->next;
	}
}



void	algo(char **edges, int nb_vertices, int max_bfs, int nb_ant)
{
	int		count;
	t_args	*args;
	t_path	*path;
	t_flow	*flow;
	int max;

	max = max_bfs;
	count = 0;
	args = init_args(nb_vertices, edges, max_bfs, nb_ant);
	while (count < args->max_bfs)
	{
		if (!(path = BFS(args, count)))
        {
            // printf("%s\n", "HERE");
			break;
        }
		set_taken(args, path);
		if (count == 0)
			flow = new_flow(path, 0);
		else
			add_flow(&flow, new_flow(path, 0));
		// printf("%s\n", "HERE");
		// print_path(path);
		count++;
		check_line(*edges);
		// printf("%s\n", "here");
		// for (int i = 0; i < args->queue.capacity; i++)
		// {
		// 	printf("--%d  et i: %d\n", args->taken[i], i);
		// }
		// printf("%s\n", "-------------");
		free_queue_vertex(args->queue);
	}
	// printf("\n---------------------------------------\nAT THE END:\n");
	*edges = ft_strdup(args->saved_map);
	free_flow(flow);
	reset(args);
	// print_map(*edges);
}
