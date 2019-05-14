#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

 
int n;
int edges[MAX][MAX];
int state[MAX];
void create_graph();
int *BF_Traversal();
int *BFS(int v);
 
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

void  get_path(int *path)
{
   int u;

   u = n - 1;
   while (u > 0)
   {
      printf("-=-=-=-%d\n", u);
      u = path[u];
   }
   printf("-=-=-=-%d\n", u);
}
 
int *BF_Traversal()
{
	int v;
	
	for(v=0; v<n; v++) 
		state[v] = initial;
	
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	return (BFS(v));
}
 
int   *BFS(int v)
{
	int i;
   int *path = malloc(10 * sizeof(int));

	insert_queue(v);
	state[v] = waiting;
	
	while(!isEmpty_queue())
	{
		v = delete_queue( );
		printf("%d ",v);
		state[v] = visited;
		
		for(i=0; i<n; i++)
		{
			if(edges[v][i] == 1 && state[i] == initial) 
			{
            path[i] = v;
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
   return (path);
}
 
void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	
	delete_item = queue[front];
	front++;
	return delete_item;
}
 
void create_graph()
{
	int count;
   int max_edge;
   int origin;
   int destin;
 
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edge = n*(n-1);
 
	for(count=1; count<=max_edge; count++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",count);
		scanf("%d %d",&origin,&destin);
 
		if((origin == -1) && (destin == -1))
			break;
 
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			count--;
		}
		else
		{
			edges[origin][destin] = 1;
			edges[destin][origin] = 1;
		}
	}
}

int main()
{
	create_graph();
	int *path = BF_Traversal();
   get_path(path);
	return 0;
}