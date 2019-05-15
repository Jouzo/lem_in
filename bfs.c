#include "algo.h"
#define MAX 100
#include <strings.h>

int state[MAX];
void create_graph();

int *BFS(int v, queue *queue, char *edges_trans);

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

int 	init_stage(queue *queue)
{
	int v;

	v = 0;
	while (v < queue->capacity)
	{
		state[v] = INITIAL;
		v++;
	}
	
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	return (v);
}
 
int   *BFS(int v, queue *queue, char *edges_trans)
{
	int i;
   	int *path;

	path = malloc(10 * sizeof(int));
	enqueue(queue, v);
	state[v] = WAITING;
	while (!is_empty(queue))
	{
		v = dequeue(queue);
		state[v] = VISITED;
		
		for (i = 0; i < queue->capacity; i++)
		{
			if(edges_trans[v * queue->capacity + i] == '1' && state[i] == INITIAL)
			{
            	path[i] = v;
				enqueue(queue, i);
				state[i] = WAITING;
			}
		}
	}
	printf("\n");
   	return (path);
}

void create_graph(queue *queue, char **edges_trans)
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
			(*edges_trans)[fst] = '1';
			(*edges_trans)[sec] = '1';
		}
	}
}

int algo()
{
	queue queue;
	int *path;
	int first_vertex;
	char *edges_trans;

	if (!(edges_trans = malloc(5 * 5 * sizeof(char) + 1)))
		return (-1);
	edges_trans[25] = '\0';
	ft_memset(edges_trans, '0', 25);

	queue = *create_queue(5);
	create_graph(&queue, &edges_trans);
	first_vertex = init_stage(&queue);
	path = BFS(first_vertex, &queue, edges_trans);
   	get_path(path, queue);
	return 0;
}

int main()
{
	algo();
}