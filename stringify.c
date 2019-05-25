#include "includes/lem_in.h"

void	fill_string(char **s, int x, int y, int size)
{
	(*s)[y * size + x] = '1';
	(*s)[x * size + y] = '1';
}

char	**split_vertices(t_vertices *head)
{
	char		**split;
	t_vertices	*tmp;
	int			i;

	i = 0;
	tmp = head;
	if (!(split = (char**)malloc(sizeof(char*) * vertices_len(head) + 1)))
		return (NULL);
	while (tmp)
	{
		if (!(split[i] = ft_strdup(tmp->name)))
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (split);
}

void	get_coordinates(t_edges *edge, char **split, int *x, int *y)
{
	int size;

	size = split_count(split);
	while (*x < size)
	{
		if (ft_strcmp(split[*x], edge->from) == 0
			|| ft_strcmp(split[*x], edge->to) == 0)
		{
			(*y)++;
			break ;
		}
		(*y)++;
		(*x)++;
	}
	while (*y < size)
	{
		if (ft_strcmp(split[*y], edge->from) == 0
			|| ft_strcmp(split[*y], edge->to) == 0)
			break ;
		(*y)++;
	}
}

int		assign(t_edges *edge, t_vertices *vertice, char **s, int size)
{
	t_edges	*tmp;
	int		x;
	int		y;
	char	**split;

	if (!(split = split_vertices(vertice)))
		return (-1);
	tmp = edge;
	while (tmp)
	{
		x = 0;
		y = 0;
		get_coordinates(tmp, split, &x, &y);
		fill_string(s, x, y, size);
		tmp = tmp->next;
	}
	return (1);
}

void print_map(int size, char *s)
{
	int i;
	char *one;
	char *two;
	
	one = "\x1B[31m1 \033[0m";
	two = "\x1B[32m2 \033[0m";
	i = 0;
	while (i < size * size)
	{
		if (s[i] == '1')
			write(1, one, ft_strlen(one));
		else if (s[i] == '2')
			write(1, two, ft_strlen(one));
		else 
			write(1, "0 ", 2);
		if ((i + 1) % size == 0)
		{
			write(1, "\n", 1);
		}
		i++;
	}
}

char	*stringify(t_data *data)
{
	char	*s;
	size_t	size;

	size = vertices_len(data->vertices);
	if (!(s = (char*)malloc(sizeof(char) * size * size + 1)))
		return (NULL);
	ft_memset(s, '0', size * size);
	s[size * size] = '\0';
	if (assign(data->edges, data->vertices, &s, size) == -1)
		return (NULL);
	print_map(size, s);
	return (s);
}
