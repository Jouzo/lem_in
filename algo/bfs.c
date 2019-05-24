#include "./includes/algo.h"

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int		check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

t_path  *get_path(int *path, t_queue queue, char *edges)
{
	(void)edges;
	int u;
	t_path *aug_path;

	u = queue.capacity - 1;
	aug_path = init_path(u);
	if (path[u] == 0 && edges[u] == '0')
	{
		free(path);
		return (aug_path);
	}		
	while (u > 0)
	{
		u = path[u];
		push_vertex(&aug_path, u);
	}
	free(path);
	return (aug_path);
}

int  get_path_size(int *path, int sink, int vertex)
{
	int size;

	size = 0;
	path[sink] = vertex;
	while (sink > 0)
	{
		sink = path[sink];
		size++;
	}
	return (size);
}

int		check_flow(int *path, int vertex, t_flow *flow, int stage, int vertex_source)
{
	int size;
	int tmp;
	t_flow *flow_tmp;
	t_path *path_tmp;

	if (stage == 0)
		return (1);
	size = get_path_size(path, vertex, vertex_source);
	flow_tmp = flow;
	while (flow_tmp)
	{
		tmp = size;
		path_tmp = flow_tmp->path;
		while (path_tmp && tmp)
		{
			path_tmp = path_tmp->next;
			tmp--;
		}
		if (path_tmp && path_tmp->vertex == vertex)
		{
			return (0);
		}
		flow_tmp = flow_tmp->next;
	}
	return (1);
}

void	bzero_tab(int *tab, int size)
{
	while (size)
		tab[size--] = 0;		
}

// t_path		*find_path(t_queue *queue, char *edges, char **state, t_flow *flow, int stage)
t_path		*find_path(t_args *args, t_flow *flow, int stage)
{
	int vertex;
	int *path;

	if (!(path = malloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	bzero_tab(path, args->queue.capacity); 
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		for (int i = 1; i < args->queue.capacity; i++)
		{
			if (args->edges[vertex * args->queue.capacity + i] == '1' && check_available(args->state, i) 
				&& (i == args->queue.capacity - 1 || check_flow(path, i, flow, stage, vertex)))
			{
				path[i] = vertex;
				enqueue(&args->queue, i);
				change_state(&args->state, i, WAITING);
			}
		}
	}
	// if (path[queue->capacity - 1] == 0 && edges[queue->capacity - 1] == '0')	
	return (get_path(path, args->queue, args->edges));
}

t_path		*BFS(t_args *args, t_flow *flow, int stage, int nb_vertices, char **edges)
{
	(void)edges;
	(void)nb_vertices;

	printf("---start of bfs---\n");
	printf("\n");

	reinit_args(args);
	enqueue(&args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args, flow, stage));
}
