#include "./includes/algo.h"

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
	int count;
	t_args *args;
	t_path *new_path;
	t_flow *flow;

	count = 0;
	while (count < nb_ants)
	{
		args = init_args(nb_vertices);
		ft_memset(args->state, '1', nb_vertices);
		path = BFS(&args->queue, *edges, &args->state, flow, count);
   		new_path = get_path(path, args->queue, *edges);
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
	int nb_vertices = 6;

	if (!(edges = malloc(nb_vertices * nb_vertices * sizeof(char) + 1)))
		return (-1);
	edges[nb_vertices * nb_vertices] = '\0';
	ft_memset(edges, '0', nb_vertices * nb_vertices);

	// nb_vertices = create_graph(&edges);
	// char *bis_edges = "0111000010001000100001001000001001000001001000010001000100001110";
	char *bis_edges = "011000100100100110011001001001000110";
	// algo(&edges, nb_vertices, 3);
	algo(&bis_edges, nb_vertices, 2);
	// free(edges); //to uncomment with the create_graph line above
	return (0);
}