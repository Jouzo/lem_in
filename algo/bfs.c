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
	// if (path[u] == 0 && edges[u] == '0')
	// 	return (aug_path);
	while (u > 0)
	{
		u = path[u];
		push_vertex(&aug_path, u);
	}
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
			// printf("oups===%d\n", vertex);
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

int		*find_path(t_queue *queue, char *edges, char **state, t_flow *flow, int stage)
{
	int vertex;
	int *path;

	if (!(path = malloc(queue->capacity * sizeof(int))))
		return (NULL);
	bzero_tab(path, queue->capacity); 

	while (!is_empty(queue))
	{
		vertex = dequeue(queue);
		change_state(state, vertex, VISITED);
		for (int i = 1; i < queue->capacity; i++)
		{
			if (edges[vertex * queue->capacity + i] == '1' && check_available(*state, i) 
				&& (i == queue->capacity - 1 || check_flow(path, i, flow, stage, vertex)))
			{
				path[i] = vertex;
				enqueue(queue, i);
				change_state(state, i, WAITING);
			}
		}
	}
	return (path);
}

int		*BFS(t_queue *queue, char *edges, char **state, t_flow *flow, int stage)
{
	int *path;

	printf("---start of bfs---\n");
	enqueue(queue, 0);
	change_state(state, 0, WAITING);
	path = find_path(queue, edges, state, flow, stage);
	printf("---end of bfs---\n");
	printf("\n");
   	return (path);
}
