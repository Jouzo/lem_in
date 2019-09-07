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

void	next_vertex(t_args *args, int *path, int vertex, int to, int *back)
{
	// printf("-=-=-%d\n", to);
	path[to] = vertex;
	enqueue(&args->queue, to);
	change_state(&args->state, to, WAITING);
	*back = 0;
}


t_path	*find_path(t_args *args, int stage)
{
	int vertex;
	int *path;
	int to;
	(void)stage;
	int rev;
	int back = 0;
	int rev2 = 0;
	int *back_test;

	rev = 0;
	if (!(back_test = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	if (!(path = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		to = 1;
		printf("%s\n", "");
		printf("vertex: %d\n", vertex);
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
			// printf("%d\n", to);
			if (check_connection(args, vertex, to))
			{
				// printf("--0--vertex: %d, to: %d\n", vertex, to);
				if (args->taken[vertex])
				{
					rev = check_test(vertex, args);

					// if (rev && path[rev])

					if (!back_test[vertex] && rev != -1) {
						printf("--1--vertex: %d, to: %d et rev:%d et back_test: %d\n", vertex, to, rev, back_test[vertex]);
						// next_vertex(args, path, vertex, rev, &back);
						next_vertex(args, path, vertex, rev, &back_test[vertex]);
						back_test[rev] = 1;
						printf("%s\n", "BRK");
						printf("%s\n", "");
						break;
					}
					// else if (check_available(args->state, rev) && !back_test[rev]) {
					// 	printf(YEL"--TAKEN VERTEX TO REV %d, %d\n"RESET, vertex, to);
					// 	next_vertex(args, path, vertex, rev, &back_test[rev]);
					// }
					else if (check_available(args->state, to) && !back_test[to]) {
						printf(GRN"--TAKEN VERTEX TO TO %d, %d\n"RESET, vertex, to);
						next_vertex(args, path, vertex, to, &back_test[to]);
						if (rev == to) {
							back_test[rev] = 1;
						}
					}
					else {
							printf(BLU"--5--VERTEX: %d, TO: %d, REV: %d\n"RESET, vertex, to, rev);
							printf(RED"--5-- back_test[vertex] %d,\n"RESET, back_test[vertex]);

					}
				}
				else {
					if (check_available(args->state, to) && check_link(args, vertex, to)) {
						if ((rev2 = check_test(to, args) != -1) && !path[to])
						{
						printf("--2--vertex: %d, to: %d\n", vertex, to);
							// printf(RED"rev2: %d, vertex: %d, to: %d\n"RESET, rev2, vertex,	 to);
							// printf("%s\n", "going back mofo");
							next_vertex(args, path, vertex, to, &back_test[vertex]);
						}
						else if ((stage == 0 || !args->taken[to]))
						{
						printf("--3--vertex: %d, to: %d\n", vertex, to);
							// printf("%s\n", "in last if");
							next_vertex(args, path, vertex, to, &back_test[vertex]);
							if (check_end(args, vertex, to)) {
								// printf("%s\n", "first ret----------------");
								return (get_path(path, args));
							}
						} else { 
							printf("--4-- rev2: %d, vertex: %d, to: %d,\n", rev2, vertex, to);
							}
					}
				}
				}
			to++;
		}
	}
	return (get_path(path, args));
}
