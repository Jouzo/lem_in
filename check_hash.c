#include "lem_in.h"

static int parse_source_sink(char *s, t_data *data)
{
    printf("value of s in parse source sink : %s\n, *set_source : %d\n, *set_sink %d : \n", s, data->set_source, data->set_sink);
    if (s)
    {
    if (strcmp(s, "##start") == 0 && data->set_source == 0)
    {
        data->set_source = 1;
        return (1);
    }
    else if (strcmp(s, "##start") == 0 && data->set_source)
        return (-1);
    else if (strcmp(s, "##end") == 0 && !data->set_sink)
    {
        data->set_sink = 1;
        return (1);
    }
    else if (strcmp(s, "##end") == 0 && data->set_sink)
        return (-1);
    return (-1);
    }
    else
        return (-1);
}

int check_hash(t_data *data, char *s)
{
	printf("inside parse %d %d\n", data->set_sink, data->set_source);
	if (s[0] == '#' && s[1] == '#')
	{
		if (parse_source_sink(s, data) == -1)
			return (-1);
	}
	else if (s[0] == '#' && s[1] != '#')
	{
		printf("it's a comment : %s\n", s);
		return (1);
	}
    return (1);
}