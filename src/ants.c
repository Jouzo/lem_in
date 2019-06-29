#include "lem_in.h"

static void			count_ants_per_path(t_flow *flow)
{
	int i;
	t_flow *tmp;

	tmp = flow;
	i = 0;
	while (tmp->next) 
	{
		tmp->next->ants = -(tmp->next->size - flow->size);
		tmp = tmp->next;
	}
	flow->ants = 0;
}

static int			*get_ants_tab(t_flow *flow, int nb_path)
{
	int		i;
	t_flow	*tmp;
	int		*tab;

	if (!(tab = (int*)malloc(sizeof(int) * nb_path)))
		return (NULL);
	tmp = flow;
	i = 0;
	while (tmp) 
	{
		tab[i] = tmp->ants;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

static int			assign_ants_per_path(t_flow *flow, int *ants)
{
	int		i;
	t_flow	*tmp;

	tmp = flow;
	i = 0;
	while (tmp)
	{
		tmp->ants = ants[i++];
		tmp = tmp->next;
	}
	// print_flow(flow);
	free(ants);
	return (1);
}

int					get_ants_per_path(t_flow *flow, int nb_ants, int nb_path)
{
	int		i;
	t_flow	*tmp;
	int		*ants;
	int		count;

	count = 0;
	count_ants_per_path(flow);
	if (!(ants = get_ants_tab(flow, nb_path)))
		return (-1);
	tmp = flow;
	while (count < nb_ants) 
	{
	i = 0;
		while (i < nb_path && count < nb_ants)
		{
			if (ants[i] >= 0)
				count++;
			(ants[i++])++;
		}
	}
	return (assign_ants_per_path(flow, ants));
}