#include "parsing.h"
#include "libft.h"

void	fill_string(char **s, int x, int y, int size)
{
	(*s)[y * size + x] |= LINK;
	(*s)[x * size + y] |= LINK;
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

int		stringify(t_data *data, char **map)
{
	int		size;

	size = vertices_len(data->vertices);
	if (!(*map = ft_strnew(sizeof(char) * size * size)))
		return (0);
	ft_memset(*map, '0', size * size);
	if (assign(data->edges, data->vertices, map, size) == -1)
		return (0);
	return (size);
}
