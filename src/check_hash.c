#include "lem_in.h"

static int		parse_source_sink(char *s, t_data *data)
{
	if (s)
	{
		if (!strcmp(s, "##start") && !data->set_source)
		{
			data->set_source = 1;
			return (1);
		}
		else if (!strcmp(s, "##start") && data->set_source)
			return (-1);
		else if (!strcmp(s, "##end") && !data->set_sink)
		{
			data->set_sink = 1;
			return (1);
		}
		else if (!strcmp(s, "##end") && data->set_sink)
			return (-1);
		return (-1);
	}
	else
		return (-1);
}

int				check_hash(t_data *data, char *s)
{
	if (s)
	{
		if (s[0] == '#' && s[1] == '#')
		{
			if ((data->set_source && !data->source) || (data->set_sink && !data->sink))
				return (-1);
			if (parse_source_sink(s, data) == -1)
				return (-1);
		}
		else if (s[0] == '#' && s[1] != '#')
		{
			return (1);
		}
		return (1);
	}
	else
		return (-1);
}
