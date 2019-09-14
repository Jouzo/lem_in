#include "lem_in.h"

static t_args	*init_args(int nb_vertices, char **edges, int max_bfs, int nb_ant)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = ft_strnew(nb_vertices)))
		return (NULL);
	if (!(args->saved_map = ft_strnew(nb_vertices * nb_vertices)))
		return (NULL);
	if (!(args->taken = ft_memalloc((nb_vertices + 1) * sizeof(int))))
		return (NULL);
	ft_memset(args->state, INITIAL, nb_vertices);
	args->max_bfs = max_bfs;
	args->nb_ant = nb_ant;
	args->step_number = 0;
	args->edges = ft_strdup(*edges);
	args->nb_vertice = nb_vertices;
	args->queue = create_queue();
	return (args);
}

void	reinit_args(t_args *args)
{
	ft_memset(args->state, INITIAL, ft_strlen(args->state));
	initialize(args->queue);
}

/*
in the matrix, check if there is more than two '2 in the line
which means the paths found are invlalid
*/

void	check_line(char *map, int size)
{
	int i;
	int j;
	int count;

	i = 0;
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (map[i * size + j] & TAKEN)
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

void	free_args(t_args *args)
{
	free(args->taken);
	free(args->state);
	free(args->edges);
	free(args->queue);
	free(args->saved_map);
	free(args);
}

void	algo(char **edges, int size, int max_bfs, int nb_ant)
{
	int		count;
	t_args	*args;
	t_path	*path;
	t_flow	*flow;
	int max;

	max = max_bfs;
	count = max_bfs;
	args = init_args(size, edges, max_bfs, nb_ant);
	while (count > 0)
	{
		if (!(path = BFS(args)))
			break;
		set_taken(args, path);
		if (count == max_bfs)
			flow = new_flow(path, 0);
		else
			add_flow(&flow, new_flow(path, 0));
		count--;
		check_line(*edges, args->nb_ant);
		free_queue_vertex(args->queue);
	}
	ft_memcpy(*edges, args->saved_map, size * size);
	free_flow(flow);
	free_args(args);
}
