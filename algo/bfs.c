#include "./includes/algo.h"

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int		check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

t_vertex  *get_path(int *path, t_queue queue)
{
	int u;
	t_vertex *aug_path;

	u = queue.capacity - 1;
	aug_path = init_path(u);
	while (u > 0)
	{
		u = path[u];
		push_vertex(&aug_path, u);
	}
	return (aug_path);
}

int  get_path_size(int *path, int sink)
{
	int size;

	size = 0;
	while (sink > 0)
	{
		sink = path[sink];
		size++;
	}
	return (size);
}

int		check_flow(int *path, int vertex, t_flow *flow, int stage)
{
	int size;
	int tmp;
	t_flow *flow_tmp;
	t_vertex *path_tmp;

	if (stage == 0)
		return (1);
	size = get_path_size(path, vertex);	
	flow_tmp = flow;
	while (flow_tmp)
	{
		tmp = size;
		path_tmp = flow_tmp->flow;
		while (path_tmp && tmp)
		{
			path_tmp = path_tmp->next;
			tmp--;
		}
		if (path_tmp && path_tmp->vertex == vertex)
			return (0);
		flow_tmp = flow_tmp->next;
	}
	return (1);
}

void	bzero_tab(int *tab, int size)
{
	for (int j = 0; j < size; j++)
		tab[j] = 0;
}

int		*BFS(t_queue *queue, char *edges, char **state, t_flow *flow, int stage)
{
	int i;
	int *path;
	int vertex;

	printf("---start of bfs---\n");
	vertex = 0;
	if (!(path = malloc(queue->capacity * sizeof(int))))
		return (NULL);
	bzero_tab(path, queue->capacity); 
	enqueue(queue, vertex);
	change_state(state, vertex, WAITING);
	while (!is_empty(queue))
	{
		vertex = dequeue(queue);
		change_state(state, vertex, VISITED);
		for (i = 0; i < queue->capacity; i++)
		{
			if (edges[vertex * queue->capacity + i] == '1' && check_available(*state, i) && (check_flow(path, i, flow, stage) || i == queue->capacity - 1))
			{
				// printf("src: %d  dest: %d   auto: %d\n", vertex, i, check_flow(path, i, flow, stage));
				path[i] = vertex;
				enqueue(queue, i);
				change_state(state, i, WAITING);
			}
		}
	}
	printf("---end of bfs---\n");
	printf("\n");
   	return (path);
}
