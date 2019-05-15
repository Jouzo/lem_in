#include "algo.h"

void create_graph();

int *BFS(int v, queue *queue, char *edges, char **state_state);

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

// void	check_edge()

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

int 	init_stage(queue *queue, char **state)
{
	int v;

	v = 0;
	ft_memset(*state, '1', 5);
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

void create_graph(queue *queue, char **edges)
{
	int count;
	int max_edge;
	int origin;
	int destin;
 
	printf("Enter number of vertices : ");
	scanf("%d", &queue->capacity);
	max_edge = queue->capacity * (queue->capacity - 1);
	for(count=1; count<=max_edge; count++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",count);
		scanf("%d %d",&origin,&destin);
 
		if((origin == -1) && (destin == -1))
			break;
 
		if(origin>=queue->capacity || destin>=queue->capacity || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			count--;
		}
		else
		{
			int fst = origin * (queue->capacity) + destin;
			int sec = destin * (queue->capacity) + origin;
			(*edges)[fst] = '1';
			(*edges)[sec] = '1';
		}
	}
}

int algo(char **edges)
{
	queue queue;
	int *path;
	int first_vertex;
	char *state;
	
	state = malloc(6);
	state[5] = '\0';

	queue = *create_queue(5);
	create_graph(&queue, edges);
	first_vertex = init_stage(&queue, &state);
	path = BFS(first_vertex, &queue, *edges, &state);
   	get_path(path, queue);
	return 0;
}

int main()
{
	char *edges;

	if (!(edges = malloc(5 * 5 * sizeof(char) + 1)))
		return (-1);
	edges[25] = '\0';
	ft_memset(edges, '0', 25);
	algo(&edges);
}