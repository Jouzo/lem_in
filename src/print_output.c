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

static int		nb_used_path(t_flow *flow)
{
	t_flow	*tmp;
	int		count;

	count = 0;
	tmp = flow;
	while (tmp && tmp->ants > 0)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static void		send_ants_in_path(t_flow *flow, int count, char **vertices)
{
	t_path		*tmp;
	int			size;
	static int	ant_id = 1;

	size = 0;
	tmp = flow->path;
	while (vertices[size])
		size++;
	if (flow->ants > count)
		tmp->ant = ant_id++;
	while (tmp)
	{
		if (tmp->ant)
		{
			(g_color > 0 && (tmp->vertex == size - 1))
				? write(1, RED, 5) : 0;
			(g_color > 0 && (tmp->vertex == size - 1))
				? write(1, RST, 4) : 0;
			formatted_output(vertices[tmp->vertex], tmp->ant);
			ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	move_up_path(flow->path);
}

void			print_output(char **vertices, t_flow *flow, int color)
{
	t_flow	*tmp;
	int		path_id;
	int		count;
	int		nb_path;

	nb_path = nb_used_path(flow);
	g_color = color;
	count = 0;
	while (count < flow->ants + flow->size - 1)
	{
		tmp = flow;
		path_id = 1;
		while (path_id <= nb_path)
		{
			send_ants_in_path(tmp, count, vertices);
			path_id++;
			tmp = tmp->next;
		}
		ft_putchar('\n');
		count++;
	}
}
