#include "lem_in.h"

void	fill_string(char **s, int x, int y, int size)
{
	(*s)[y * size + x] = '1';
	(*s)[x * size + y] = '1';
}

void	get_coordinates(t_edges *edge, char **split, int *x, int *y)
{
	int size;

	size = split_count(split);
	while (*x < size)
	{
		if (!ft_strcmp(split[*x], edge->from)
				|| !ft_strcmp(split[*x], edge->to))
		{
			(*y)++;
			break ;
		}
		(*y)++;
		(*x)++;
	}
	while (*y < size)
	{
		if (!ft_strcmp(split[*y], edge->from)
				|| !ft_strcmp(split[*y], edge->to))
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

	split = NULL;
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
	return (free_split(split, 1));
}

char	*stringify(t_data *data)
{
	char	*s;
	size_t	size;

	size = 0;
	size = vertices_len(data->vertices);
	if (!(s = ft_strnew(sizeof(char) * size * size)))
		return (NULL);
	ft_memset(s, '0', size * size);
	if (assign(data->edges, data->vertices, &s, size) == -1)
		return (NULL);
	// print_map(s);
	return (s);
}
