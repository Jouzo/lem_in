#include "./includes/algo.h"

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int		check_available(char *state, int vertex)
{
	if (state[vertex] == '1')
		return (1);
	else
		return (0);		
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
	sink--;
	int size = 1;

	while (sink > 0)
	{
		sink = path[sink];
		size++;
	}
	// printf("value of sink: %d and value of size: %d\n", sink, size);
	return (size);
}

int 	init_state(t_args *args, int nb_vertices)
{
	int v;

	v = 0;
	ft_memset(args->state, '1', nb_vertices);
	// printf("Enter Start Vertex for BFS: \n");
	// scanf("%d", &v);
	return (v);
}

int		check_flow(int *path, int vertex, t_flow *flow)
{
	(void)flow;
	int size;
	int tmp;
	t_flow *flow_tmp;
	t_vertex *path_tmp;

	size = get_path_size(path, vertex);
	flow_tmp = flow;
	while (flow_tmp)
	{
		tmp = size;
		path_tmp = flow_tmp->flow;
		while (flow_tmp->flow && tmp)
		{
			path_tmp = path_tmp->next;
			tmp--;
		}
		// printf("vertex to check: %d and vertex in path: %d and size: %d\n", vertex, path_tmp->vertex, size);
		if (path_tmp && path_tmp->vertex == vertex)
				return (0);
				// printf("*****vertex checking: %d and vertex inside path: %d\n", vertex, path_tmp->vertex);
		flow_tmp = flow_tmp->next;
	}
	return (1);
}

int		*BFS(int vertex, t_queue *queue, char *edges, char **state, t_flow *flow, int stage)
{
	int i;
	int *path;
	(void)stage;
	// (void)flow;

	printf("---start of bfs---\n");
	if (!(path = malloc(queue->capacity * sizeof(int))))
		return (NULL);
	enqueue(queue, vertex);
	change_state(state, vertex, WAITING);
	while (!is_empty(queue))
	{
		vertex = dequeue(queue);
		change_state(state, vertex, VISITED);
		for (i = 0; i < queue->capacity; i++)
		{
			if(edges[vertex * queue->capacity + i] == '1' && check_available(*state, i))
			{
				// if (check_flow(path, i, flow) == 1 || vertex == 7)
				// {
					printf("source: %d and destination: %d and check_flow: %d\n", vertex, i, check_flow(path, i, flow));
            		path[i] = vertex;
					enqueue(queue, i);
					change_state(state, i, WAITING);
				// }
			}
		}
	}
	printf("---end of bfs---\n");
	printf("\n");
   	return (path);
}

static t_args *init_args(int nb_vertices)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = malloc(nb_vertices + 1)))
		return (NULL);
	args->state[nb_vertices] = '\0';
	args->queue = create_queue(nb_vertices);
	return (args);
}

int algo(char **edges, int nb_vertices, int nb_ants)
{
	int *path;
	int first_vertex;
	int count;
	t_args *args;
	t_vertex *new_path;
	t_flow *flow;

	count = 0;
	while (count < nb_ants)
	{
		args = init_args(nb_vertices);
		first_vertex = init_state(args, nb_vertices);
		path = BFS(first_vertex, &args->queue, *edges, &args->state, flow, count);
   		new_path = get_path(path, args->queue);
		if (count == 0)
			flow = new_flow(new_path);
		else
			add_flow(flow, new_path);
		reset(path, args);
		count++;
	}
	print_flow(flow);
	free_flow(flow);
	return (0);
}

// this function will be deleted. just for develloping
int create_graph(char **edges)
{
	int count;
	int max_edge;
	int origin;
	int destin;
	int nb_vertices;
 
	printf("Enter number of vertices : ");
	scanf("%d", &nb_vertices);
	max_edge = nb_vertices * (nb_vertices - 1) / 2;
	count = 1;
	while (count <= max_edge)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",count);
		scanf("%d %d",&origin,&destin);
 
		if((origin == -1) && (destin == -1))
			break;
 
		if(origin>=nb_vertices || destin>=nb_vertices || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			count--;
		}
		else
		{
			int fst = origin * nb_vertices + destin;
			int sec = destin * nb_vertices + origin;
			(*edges)[fst] = '1';
			(*edges)[sec] = '1';
		}
		count++;
	}
	return nb_vertices;
}

// this function will be deleted. just for develloping
int pre_main()
{
	char *edges;
	int nb_vertices = 8;

	if (!(edges = malloc(nb_vertices * nb_vertices * sizeof(char) + 1)))
		return (-1);
	edges[nb_vertices * nb_vertices] = '\0';
	ft_memset(edges, '0', nb_vertices * nb_vertices);

	// nb_vertices = create_graph(&edges);
	edges = "0111000010001000100001001000001001000001001000010001000100001110";
	algo(&edges, nb_vertices, 3);
	// free(edges); //to uncomment with the create_graph line above
	return (0);
}