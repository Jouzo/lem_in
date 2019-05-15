#include "algo.h"

int *BFS(int v, queue *queue, char *edges, char **state_state);

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

// void	check_edge(char *edges, int state, int vertex, queue *queue)
// {
// 	edges[vertex * queue->capacity + i] == '1'
// }

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;

    ptr = b;
    while (len--)
            *ptr++ = (unsigned char)c;
    return (b);
}

void  get_path(int *path, queue queue)
{
   int u;

   u = queue.capacity - 1;
   while (u > 0)
   {
      printf("-=-=-=-%d\n", u);
      u = path[u];
   }
   printf("-=-=-=-%d\n", u);
}

int 	init_stage(char **state, int nb_vertices)
{
	int v;

	v = 0;
	ft_memset(*state, '1', nb_vertices);
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	return (v);
}
 
int   *BFS(int vertex, queue *queue, char *edges, char **state)
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
			if(edges[vertex * queue->capacity + i] == '1' && (*state)[i] == '1')
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

static int init_args(t_args *args, int nb_vertices)
{
	if (!(args = malloc(sizeof(t_args))))
		return (-1);
	args->state = malloc(nb_vertices + 1);
	args->state[nb_vertices] = '\0';
	args->queue = create_queue(nb_vertices);
	return (0);
}

int algo(char **edges, int nb_vertices)
{
	int *path;
	int first_vertex;
	t_args args;

	init_args(&args, nb_vertices);
	first_vertex = init_stage(&args.state, nb_vertices);
	path = BFS(first_vertex, &args.queue, *edges, &args.state);
   	get_path(path, args.queue);
	return 0;
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
int main()
{
	char *edges;
	int nb_vertices = 5;

	if (!(edges = malloc(nb_vertices * nb_vertices * sizeof(char) + 1)))
		return (-1);
	edges[nb_vertices * nb_vertices] = '\0';
	ft_memset(edges, '0', nb_vertices * nb_vertices);

	nb_vertices = create_graph(&edges);

	algo(&edges, nb_vertices);
}