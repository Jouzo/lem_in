#include "lem_in.h"

int g_color = 0;

static int		formatted_output(char *vertex, int ant)
{
	char	*s;
	int		size;
	char	*ant_to_a;

	size = ft_sizeofint(ant);
	if (!(ant_to_a = ft_itoa(ant)))
		return (0);
	if (!(s = ft_strnew(size + ft_strlen(vertex) + 2)))
		return (0);
	s[size + ft_strlen(vertex) + 2] = 0;
	s[0] = 'L';
	s = ft_strcat(s, ant_to_a);
	s[size + 1] = '-';
	s = ft_strcat(s, vertex);
	write(1, s, ft_strlen(s));
	ft_memdel((void**)&s);
	ft_memdel((void**)&ant_to_a);
	return (1);
}

static void		move_up_path(t_path *path)
{
	t_path	*list;
	int		tmp;
	int		tmp2;
	int		check;

	list = path;
	tmp = list->ant;
	list->ant = 0;
	while (list->next)
	{
		check = list->ant > check ? list->ant : check;
		list = list->next;
		tmp2 = list->ant;
		list->ant = tmp;
		tmp = tmp2;
	}
}

// static void		print_ants_in_path(t_flow *flow,
// 					char **vertices, int ant, int *ants)
// {
// 	t_path	*tmp;
// 	int		size;

// 	size = 0;
// 	while (vertices[size])
// 		size++;
// 	tmp = flow->path;
// 	tmp->ant = ant;
// 	while (tmp)
// 	{
// 		if (tmp->ant > 0)
// 		{
// 			(g_color > 0 && (tmp->vertex == size - 1))
// 				? write(1, "\x1B[31m", 5) : 0;
// 			formatted_output(vertices[tmp->vertex], tmp->ant);
// 			(g_color > 0 && (tmp->vertex == size - 1))
// 				? write(1, "\x1B[0m", 4) : 0;
// 			ft_putchar(' ');
// 			if (tmp->vertex == size - 1)
// 				(*ants)--;
// 		}
// 		tmp = tmp->next;
// 	}
// 	move_up_path(flow->path);
// }

static int				nb_used_path(t_flow *flow)
{
	t_flow *tmp;
	int count;

	count = 0;
	tmp = flow;
	while (tmp && tmp->ants > 0)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static void			send_ants_in_path(t_flow *flow, int count, int path_id, char **vertices, int nb_path)
{
	t_path *tmp;
	int nb_ants = flow->ants;
	int		size;

	size = 0;
	while (vertices[size])
		size++;
	tmp = flow->path;
	if (nb_ants > count)
		tmp->ant = count + path_id;
	while (tmp)
	{
		if (tmp->ant)
		{
			(g_color > 0 && (tmp->vertex == size - 1))
				? write(1, RED, 5) : 0;
			(g_color > 0 && (tmp->vertex == size - 1))
				? write(1, RESET, 4) : 0;
			formatted_output(vertices[tmp->vertex], tmp->ant);
		}
		tmp = tmp->next;
	}
	ft_putchar(' ');		
	move_up_path(flow->path);
}

void			print_output(char **vertices, t_flow *flow, int ants, int color)
{
	t_flow *tmp;
	int path_id;
	int count;
	int nb_path = nb_used_path(flow);
	
	g_color = color;
	path_id = 1;
	tmp = flow;
	count = 0;
	while (tmp && count < flow->ants + flow->size - 1)
	{
		while (path_id <= nb_path)
		{
			send_ants_in_path(tmp, count, path_id, vertices, nb_path);
			path_id++;
			if (!tmp->next || tmp->next->ants < 1)
			{
				path_id = 1;
				tmp = flow;
				break;
			}
			else
			{
				tmp = tmp->next;
			}
		}
		ft_putchar('\n');
		count++;
	}
}
