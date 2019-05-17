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
	// print_path(aug_path);
	return (aug_path);
}

int 	init_state(t_args *args, int nb_vertices)
{
	int v;

	v = 0;
	ft_memset(args->state, '1', nb_vertices);
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	return (v);
}
 
int   *BFS(int vertex, t_queue *queue, char *edges, char **state)
{
	int i;
   	int *path;

	path = malloc(10 * sizeof(int));
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
            	path[i] = vertex;
				enqueue(queue, i);
				change_state(state, i, WAITING);
			}
		}
	}
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

int algo(char **edges, int nb_vertices)
{
	int *path;
	int first_vertex;
	t_args *args;
	t_vertex *new_path;
	t_flow *flow;
	int test = 0;

	while (test < 5)
	{
		args = init_args(nb_vertices);
		first_vertex = init_state(args, nb_vertices);

		path = BFS(first_vertex, &args->queue, *edges, &args->state);
   		new_path = get_path(path, args->queue);
		if (test == 0)
			flow = new_flow(new_path);
		else
			add_flow(flow, new_path);
		test++;
	}
	print_flow(flow);
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
	max_edge = nb_vertices * (nb_vertices - 1);
	for(count=1; count<=max_edge; count++)
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
	}
	return nb_vertices;
}

// this function will be deleted. just for develloping
int pre_main()
{
	char *edges;
	int nb_vertices = 5;

	if (!(edges = malloc(nb_vertices * nb_vertices * sizeof(char) + 1)))
		return (-1);
	edges[nb_vertices * nb_vertices] = '\0';
	ft_memset(edges, '0', nb_vertices * nb_vertices);

	nb_vertices = create_graph(&edges);

	algo(&edges, nb_vertices);
	return (0);
}