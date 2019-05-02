#include "includes/lem_in.h"

void    init_data(t_data *data)
{    
    char	*line;

     while (get_next_line(0, &line) > 0)
	{
        parse(data, line);	
		free(line);
	}
}

int     main(int ac, char **av)
{
	int		i;
    t_data data;

	i = 1;
	if (ac < 2)
		return (0);
    init_data(&data);	    
    return (0);
}