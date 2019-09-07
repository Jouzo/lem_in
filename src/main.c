#include "lem_in.h"

static int		check_parsing(t_data data)
{
	return (data.source && data.sink && data.ants && data.edges);
}

static int		init_data(t_data *data)
{
	char	*line;
	int		ret;

	ret = 1;
	while (get_next_line(0, &line) > 0)
	{
		if (!(data->flag & QUIET))
			ft_putendl(line);
		if ((ret = parse(data, line)) <= 0)
		{
			ft_memdel((void**)&line);
			return (ret);
		}
		ft_memdel((void**)&line);
	}
	return (ret);
}

static void		lem_in(t_data *data)
{
	char *map;
	int max_bfs;

	max_bfs = 0;
	map = NULL;
	if (check_parsing(*data))
	{
		// printf("done parsing\n");
		swap_source(data);
		map = stringify(data);
		max_bfs = get_max_bfs(data->source, data->sink, data->ants, data->edges);
		// printf("max_bfs : %d\n", max_bfs);
		// print_map(map);
		algo(&map, ft_sqrt(ft_strlen(map)), max_bfs);
		// printf("done algo\n");
		if (data->flag & MAP)
			print_map(map);
		// exit(1);
		// write(1, "\n", 1);
		// printf("%s\n", "out of algo");
		output(map, data);
		ft_memdel((void**)&map);
	}
	else
		write(1, "ERROR\n", 6);
}

static int		get_flags(t_data *data, char *flag)
{
	int i;

	i = 1;
	if (flag[0] != '-')
		return (-1);
	while (flag[i])
	{
		if (flag[i] == 'q')
			data->flag |= QUIET;
		else if (flag[i] == 'c')
			data->flag |= COLOR;
		else if (flag[i] == 'm')
			data->flag |= MAP;
		else
			return (-1);
		i++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	if (ac > 1)
	{
		if (get_flags(&data, av[1]) < 0 || ac > 2)
		{
			write(1, "usage: ./lem-in [-cmv] < a lem_in map\n", 38);
			return (-1);
		}
	}
	init_data(&data);
	lem_in(&data);
	free_data(&data);
	return (0);
}
