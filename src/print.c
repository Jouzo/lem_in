#include "lem_in.h"

int g_color = 0;

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

static void		print_ants_in_path(t_flow *flow,
					char **vertices, int ant, int *ants)
{
	t_path	*tmp;
	int		size;

	size = 0;
	while (vertices[size])
		size++;
	tmp = flow->path;
	tmp->ant = ant;
	while (tmp)
	{
		if (tmp->ant > 0)
		{
			(g_color > 0 && (tmp->vertex == size - 1))
				? write(1, "\x1B[31m", 5) : 0;
			formatted_output(vertices[tmp->vertex], tmp->ant);
			(g_color > 0 && (tmp->vertex == size - 1))
				? write(1, "\x1B[0m", 4) : 0;
			ft_putchar(' ');
			if (tmp->vertex == size - 1)
				(*ants)--;
		}
		tmp = tmp->next;
	}
	move_up_path(flow->path);
}

void			print_map(char *s)
{
	int		i;
	char	*one;
	char	*two;
	int		size;

	size = ft_sqrt(ft_strlen(s));
	one = "\x1B[31m1 \033[0m";
	two = "\x1B[32m2 \033[0m";
	i = 0;
	ft_putchar('\n');
	write(1, "---------- LEM IN MAP ----------\n", 33);
	ft_putchar('\n');
	while (i < size * size)
	{
		if (s[i] == '1')
			write(1, one, ft_strlen(one));
		else if (s[i] == '2')
			write(1, two, ft_strlen(one));
		else
			write(1, "0 ", 2);
		if ((i + 1) % size == 0)
			write(1, "\n", 1);
		i++;
	}
	ft_putchar('\n');
}

void			print_output(char **vertices, t_flow *flow,
								int ants, int color)
{
	t_flow	*tmp;
	int		i;
	int		max_ants;

	g_color = color;
	max_ants = ants + 1;
	i = 1;
	while (ants)
	{
		tmp = flow;
		while (tmp && ants)
		{
			if (tmp->ants > 0)
			{
				print_ants_in_path(tmp, vertices, i, &ants);
				if (i > 0 && i < max_ants)
					i++;
			}
			if (i == max_ants)
				i = 0;
			tmp = tmp->next;
		}
		ft_putchar('\n');
	}
}
