#include "lem_in.h"

void	update_map(t_args *args, int u, int v)
{
	if (args->edges[u * args->queue.capacity + v] == TAKEN)
	{
		args->edges[u * args->queue.capacity + v] = LINK;
		args->edges[v * args->queue.capacity + u] = LINK;
	}
	else
	{
		args->edges[u * args->queue.capacity + v] = TAKEN;
		args->edges[v * args->queue.capacity + u] = TAKEN;
	}	
}

t_path	*get_path(int *path, t_args *args)
{
	int		u;
	t_path	*aug_path;

	u = args->queue.capacity - 1;
	aug_path = init_path(u);
	if (path[u] == 0 && args->edges[u] == '0')
	{
		ft_memdel((void**)&path);
		return (aug_path);
	}
	while (u > 0)
	{
		update_map(args, u, path[u]);
		u = path[u];
		push_vertex(&aug_path, u);
	}
	ft_memdel((void**)&path);
	print_path(aug_path);
	return (aug_path);
}

void	print_state(t_args *args)
{
	printf("%s\n", "========STATE");
	for (int i = 0; i < args->queue.capacity; i++)
		printf("%d\n", args->state[i]);
}

void	next_vertex(t_args *args, int *path, int vertex, int to)
{
	path[to] = vertex;
	enqueue(&args->queue, to);
	change_state(&args->state, to, WAITING);
}


t_path	*find_path(t_args *args, int stage)
{
	int vertex;
	int *path;
	int to;
	(void)stage;
	int rev;

	rev = 0;
	if (!(path = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		to = 1;
		while (to < args->queue.capacity)
		{
			
			// printf("%s\n", "here");
			// IF THE VERTEX IS ALREADY USED THEN :
			// 
			// CHECK IF THERE IS ALREADY A LINK WITH A PREVIOUS NODE WITH THE USE OF CHECK_TEST FUNCTION
			// IF REV IS POSITIVE, IT MEANS THERE IS A LINK THAT ONE SHOULD TAKE
			// CHECK IF AVAILABLE
			// CALL NEXT_VERTEX FUNCTION THEN BREAK
			// BREAK MEANS THAT IT FORCES TO GO BACK AND DOES NOT TRY OTHER POSSIBILITIES FOR THIS VERTEX

			if (args->taken[vertex])
			{

				// printf("%s\n", "Is taken:");
				// printf("%d\n", vertex);
				rev = check_test(vertex, args);
				if (rev && check_available(args->state, rev))
				{
					printf("vertex in taken: rev: %d, %d, to: %d\n", rev, vertex, to);	
					next_vertex(args, path, vertex, rev);
					break;
				}
				// else if (!rev) {
				// 	break ;
				// }
			}

			if (check_link(args, vertex, to) && check_available(args->state, to)) {
				// printf("vertex: %d, to: %d\n", vertex, to);
			if ((rev = check_test(to, args)) && !path[rev])
			{
				printf(RED"rev: %d, vertex: %d, to: %d\n"RESET, rev, vertex, to);
				printf("%s\n", "going back mofo");
				next_vertex(args, path, vertex, to);
			}
			else if (check_taken(args, to))
			{
				next_vertex(args, path, vertex, to);
				if (check_end(args, vertex, to))
					return (get_path(path, args));
			}
			}
			to++;
		}
	}
	return (get_path(path, args));
}
