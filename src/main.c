#include "lem_in.h"

static int	check_parsing(t_data data)
{
	return (data.source && data.sink && data.ants && data.edges);
}

static int   init_data(t_data *data)
{    
	char	*line;
	int 	ret;

	ret = 1;
	while (get_next_line(0, &line) > 0)
	{
		data->flag != QUIET ? ft_putendl(line) : 0;
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

	swap_source(data);
	map = stringify(data);
	algo(&map, ft_sqrt(ft_strlen(map)), data->ants);
	output(map, data);
	ft_memdel((void**)&map);
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
			data->flag = QUIET;
		else
			return (-1);
		i++;
	}
	return (1);
}

int     main(int ac, char **av)
{
	t_data data;
	
	ft_bzero(&data, sizeof(t_data));
	if (ac > 1)
	{
		if (get_flags(&data, av[1]) < 0 || ac > 2)
		{
			write(1, "usage: ./lem-in [-v] < a lem_in map\n", 36);
			return (-1);
		}
	}
	if (init_data(&data) <= 0) 
	{
		if (check_parsing(data))
			lem_in(&data);
		else
			write(1, "Error\n", 5);
	}
	else 
	{
		if (check_parsing(data))
			lem_in(&data);
		else
			write(1, "Error\n", 5);
	}
	free_data(&data);
	return (0);
}